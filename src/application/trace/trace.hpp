/*
 Femtin V0.0.1 - Copyright (C) 2015 Nicolas Boutin.
 All rights reserved

 This file is part of the Femtin distribution.

 Femtin is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License (version 2) as published by the
 Free Software Foundation.

 Femtin is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.
 */

/// ================================================================================================
///
/// \file	trace.hpp
/// \brief
/// \date	dd/mm/yyyy
/// \author	nboutin
///
/// ================================================================================================
#ifndef FOLDER_TEMPLATE_HPP_
#define FOLDER_TEMPLATE_HPP_

/// === Includes	================================================================================
/// === Namespaces	================================================================================

namespace application
{

namespace trace
{

///	uint32_t i = 0;
///
///	trace_putc('1');
///	trace_puts("ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`");
///	trace_puts("abcdefghijklmnopqrstuvwxyz{|}~");
///	trace_printf("val=%d\n", i++);
///	trace_printf("%d\n", 1234);				///"1234"
///	trace_printf("%6d,%3d%%\n", -200, 5);   ///"  -200,  5%"
///	trace_printf("%-6u\n", 100);			///"100   "
///	trace_printf("%ld\n", 12345678L);		///"12345678"
///	trace_printf("%04x\n", 0xA3);			///"00a3"
///	trace_printf("%08LX\n", 0x123ABC);		///"00123ABC"
///	trace_printf("%016b\n", 0x550F);		///"0101010100001111"
///	trace_printf("%s\n", "String");			///"String"
///	trace_printf("%-4s\n", "abc");			///"abc "
///	trace_printf("%4s\n", "abc");			///" abc"
///	trace_printf("%c\n", 'a');				///"a"
///	trace_printf("%f\n", 10.0);            	///<xprintf lacks floating point support>

void trace_initialize();
void trace_putc(const char _c);
void trace_puts(const char* _s);
void trace_printf(const char* format, ...);

/// ------------------------------------------------------------------------------------------------
}/// name
}    /// sub_name

#endif	/// FOLDER_TEMPLATE_HPP_
/// === END OF FILE	================================================================================
