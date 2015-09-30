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

private:
	/// === Private Constants	====================================================================
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
