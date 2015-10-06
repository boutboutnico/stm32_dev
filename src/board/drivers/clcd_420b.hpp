///
/// \file	lcd_i2c_driver.hpp
///	\brief	
///	\date	28/09/2015
/// \author	nboutin
///
#ifndef BOARD_DRIVERS_CLCD_420B_HPP_
#define BOARD_DRIVERS_CLCD_420B_HPP_

/// === Includes	================================================================================

#include "stm32f4xx_hal.h"
#include "femtin/ostream.hpp"
#include "femtin/freeRTOS_wrapper/semaphore/semaphore.hpp"
#include "peripheral_handler.hpp"

/// === Namespaces	================================================================================

namespace board
{

namespace mcu
{

/// === Class Declarations	========================================================================

class CLCD_420B : public PeripheralHandler, public femtin::ostream
{
public:
	/// === Public Constants	====================================================================

	static const uint8_t COLUMN_NUMBER = 20;
	static const uint8_t ROW_NUMBER = 4;

	/// === Public Declarations	====================================================================

	CLCD_420B();
	virtual ~CLCD_420B();

	bool initialize();

//	void print(char _c);
//	void print(const char* _s);
//	void printf(const char* format, ...);
//	void print(int8_t _n);
//	void print(int16_t _n);
//	void print(int32_t _n);
//	void print(uint8_t _n);
//	void print(uint16_t _n);
//	void print(uint32_t _n);
//	void print(float _n);

///	--- Operations	----------------------------------------------------------------------------

	void clear();
	void backlight(bool _is_on);
	void cursor(bool _is_on);
	void home();
	void cursor_xy(uint8_t _x, uint8_t _y);
	void move_to_row(uint8_t _y);
	void next_row();
	void store_custom(uint8_t _code, const uint8_t* _data);
	void call_custom(uint8_t _code);

private:
	/// === Private Constants	====================================================================

	static const uint8_t BUFFER_SIZE = 4;

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

	virtual void write(const char* _s, size_t _size);
	void write(const uint8_t* _buf, size_t _size);

	virtual void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *_I2C_handle);
	virtual void HAL_I2C_ErrorCallback(I2C_HandleTypeDef* _I2C_handle);

	/// === Private Attributes	====================================================================

	uint8_t buffer_write_[BUFFER_SIZE];
//	char buffer_format_[COLUMN_NUMBER * ROW_NUMBER];
	femtin::Array<char, COLUMN_NUMBER * ROW_NUMBER> buffer_;
	uint8_t current_row_;
	I2C_HandleTypeDef I2C_handle_;
	femtin::os::Semaphore SEM_I2C;
};
/// === Inlines Definitions	========================================================================

///	Centralized cast from char* to uint8_t*
inline void CLCD_420B::write(const char* _s, size_t _size)
{
	write(reinterpret_cast<const uint8_t*>(_s), _size);
}

/// === Non-Members functions	====================================================================

//template<class T>
//inline CLCD_420B& operator<<(CLCD_420B& _stream, T _arg)
//{
//	_stream.print(_arg);
//	return _stream;
//}

/// ------------------------------------------------------------------------------------------------
}///mcu
}    /// board
#endif
/// === END OF FILE	================================================================================
