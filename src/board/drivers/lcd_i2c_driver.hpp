///
/// \file	lcd_i2c_driver.hpp
///	\brief	
///	\date	28/09/2015
/// \author	nboutin
///
#ifndef BOARD_DRIVERS_LCD_I2C_DRIVER_HPP_
#define BOARD_DRIVERS_LCD_I2C_DRIVER_HPP_

/// === Includes	================================================================================

#include "stm32f4xx_hal.h"
#include "femtin/freeRTOS_wrapper/semaphore/semaphore.hpp"
#include "peripheral_handler.hpp"

/// === Namespaces	================================================================================

namespace board
{

namespace mcu
{

/// === Class Declarations	========================================================================

class LCD_I2C_Driver : public PeripheralHandler
{
public:
	/// === Public Declarations	====================================================================

	LCD_I2C_Driver();

	bool initialize();
	void write(const char* _buf, size_t _size);

	void clear();

private:
	/// === Private Constants	====================================================================

	static const uint8_t ROW_0 = 0x01;
	static const uint8_t ROW_1 = 0x02;
	static const uint8_t ROW_2 = 0x03;
	static const uint8_t ROW_3 = 0x04;
	static const uint8_t COMMAND = 0x1B;
	static const uint8_t CLEAR = 0x43;
	static const uint8_t BACKLIGHT_ON = 0x42;
	static const uint8_t CUSTOM_CHAR = 0x44;
	static const uint8_t HOME = 0x48;
	static const uint8_t CURSOR_POS = 0x4C;
	static const uint8_t CURSOR_ON = 0x53;
	static const uint8_t BACKLIGHT_OFF = 0x62;
	static const uint8_t CURSOR_OFF = 0x73;

	/// === Private Declarations	================================================================

	virtual void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *_I2C_handle);
	virtual void HAL_I2C_ErrorCallback(I2C_HandleTypeDef* _I2C_handle);

	/// === Private Attributes	====================================================================

	I2C_HandleTypeDef I2C_handle_;
	femtin::os::Semaphore SEM_I2C;
};
/// === Inlines Definitions	========================================================================

/// ------------------------------------------------------------------------------------------------
}///mcu
}    /// board
#endif
/// === END OF FILE	================================================================================
