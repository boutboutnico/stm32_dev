///
/// \file	lcd_i2c_driver.cpp
///	\brief	
///	\date	28/09/2015
/// \author	nboutin
///

#include "lcd_i2c_driver.hpp"
using namespace board::mcu;

/// === Includes	================================================================================

#include "pinout_mapping.hpp"
#include "led/led.hpp"
#include "trace/trace.hpp"

/// === Namespaces	================================================================================

using namespace application::trace;

/// === Public Definitions	========================================================================

LCD_I2C_Driver::LCD_I2C_Driver()
		: PeripheralHandler(LCD_I2C_e, &I2C_handle_), SEM_I2C(0)
{
}

/// ------------------------------------------------------------------------------------------------

bool LCD_I2C_Driver::initialize()
{
	/// --- Clocks

	/// Enable UART interface clock
	LCD_I2C_CLK_ENABLE();

	/// Enable the clocks for UART GPIOs
	LCD_I2C_GPIO_CLK_ENABLE();

	/// --- GPIOs

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;

	/// SCL
	GPIO_InitStruct.Pin = LCD_I2C_SCL_PIN;
	GPIO_InitStruct.Alternate = LCD_I2C_SCL_PIN_AF;
	HAL_GPIO_Init(const_cast<GPIO_TypeDef*>(LCD_I2C_GPIO_PORT), &GPIO_InitStruct);

	/// SDA
	GPIO_InitStruct.Pin = LCD_I2C_SDA_PIN;
	GPIO_InitStruct.Alternate = LCD_I2C_SDA_PIN_AF;
	HAL_GPIO_Init(const_cast<GPIO_TypeDef*>(LCD_I2C_GPIO_PORT), &GPIO_InitStruct);

	/// --- Interrupt

	/// \warning	Must be lower than configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY
	///				to be able to call a freeRTOS ISR routine

	/// Event Handler
	/// Configure the I2C interrupt priority
	HAL_NVIC_SetPriority(LCD_I2C_EV_IRQn, LCD_I2C_EV_IRQn_PRIO, LCD_I2C_EV_IRQn_SUBPRIO);

	/// Enable NVIC I2C IRQ handle
	HAL_NVIC_EnableIRQ(LCD_I2C_EV_IRQn);

	/// Error Handler
	/// Configure the I2C interrupt priority
	HAL_NVIC_SetPriority(LCD_I2C_ER_IRQn, LCD_I2C_ER_IRQn_PRIO, LCD_I2C_ER_IRQn_SUBPRIO);

	/// Enable NVIC I2C IRQ handle
	HAL_NVIC_EnableIRQ(LCD_I2C_ER_IRQn);

	/// --- I2C

	I2C_handle_.Instance = const_cast<I2C_TypeDef*>(LCD_I2C);
	I2C_handle_.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	I2C_handle_.Init.ClockSpeed = 400000;
	I2C_handle_.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
	I2C_handle_.Init.DutyCycle = I2C_DUTYCYCLE_16_9;
	I2C_handle_.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
	I2C_handle_.Init.NoStretchMode = I2C_NOSTRETCH_DISABLED;
	I2C_handle_.Init.OwnAddress1 = LCD_I2C_Address;
	I2C_handle_.Init.OwnAddress2 = 0;

	/// User param
	I2C_handle_.user_param = this;

	if (HAL_I2C_Init(&I2C_handle_) != HAL_OK)
	{
		return false;
	}

	return true;
}

/// ------------------------------------------------------------------------------------------------

void LCD_I2C_Driver::write(const char* _buf, size_t _size)
{
	// HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
	if (HAL_I2C_Master_Transmit_IT(&I2C_handle_, LCD_I2C_Address << 1,
									reinterpret_cast<const uint8_t*>(_buf), _size)
		!= HAL_OK)
	{
		board::led::LED_Red.on();
		trace_printf("I2C Error: %d\n", HAL_I2C_GetError(&I2C_handle_));
	}

	if (SEM_I2C.take(femtin::unit::millisecond(200)) == false)
	{
		while (1)
		{
		}
	}
}

///	------------------------------------------------------------------------------------------------

void LCD_I2C_Driver::clear()
{
	char buf[] = {COMMAND, CLEAR};
	write(buf, 2);
	/// TODO : delay de 15 ms
}

/// === Private Definitions	========================================================================

void LCD_I2C_Driver::HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *_I2C_handle)
{
	if (_I2C_handle->Instance == LCD_I2C)
	{
		SEM_I2C.giveFromISR();
	}
}

/// ------------------------------------------------------------------------------------------------

void LCD_I2C_Driver::HAL_I2C_ErrorCallback(I2C_HandleTypeDef* _I2C_handle)
{
	if (_I2C_handle->Instance == LCD_I2C)
	{
		switch (_I2C_handle->ErrorCode)
		{
		case HAL_I2C_ERROR_NONE:
		case HAL_I2C_ERROR_BERR:
		case HAL_I2C_ERROR_ARLO:
		case HAL_I2C_ERROR_AF:
		case HAL_I2C_ERROR_OVR:
		case HAL_I2C_ERROR_DMA:
		case HAL_I2C_ERROR_TIMEOUT:

			board::led::LED_Red.on();
			while (1)
			{
			}
			break;
		}
	}
}

/// === END OF FILE	================================================================================
