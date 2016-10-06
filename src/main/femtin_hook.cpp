///
/// \file	femtin_hook.cpp
///	\brief	
///	\date	2 janv. 2016
/// \author	nb_work
///

#include "femtin_hook.hpp"

/// === Includes

#include "board/stm32f4-discovery/bsp/trace_uart/trace_uart.hpp"

/// === Namespaces
/// === Extern Declarations

extern board::mcu::Trace_UART trace;

/// === Public Definitions

void femtin_write(const char* _str, size_t _size)
{
	board::mcu::trace.write(reinterpret_cast<const uint8_t*>(_str), _size);
}
