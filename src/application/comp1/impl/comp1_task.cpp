///
/// \file	template.hpp
///	\brief
///	\date	dd/mm/yyyy
/// \author	author
///

#include "comp1_task.hpp"
using namespace application::comp1;

/// === Includes	================================================================================

#include <cstring>

#include "femtin/freeRTOS_wrapper/delay.hpp"
#include "femtin/freeRTOS_wrapper/direct_task_notification/direct_task_notification.hpp"

#include "appli_conf.hpp"
#include "led/led.hpp"

#include "trace/trace.hpp"
//#include "diag/Trace.h"

/// === Namespaces	================================================================================

using namespace os;
//using namespace board::mcu;
using namespace board::led;
using namespace application::system_controller;
using namespace application::trace;

/// === Public Definitions	========================================================================

Comp1_Task::Comp1_Task()
		: Task(application::COMP1_TASK_NAME.c_str(), application::COMP1_TASK_STACK_SIZE,
				application::COMP1_TASK_PRIO)
{
	suspend();
}

/// ------------------------------------------------------------------------------------------------

bool Comp1_Task::initialize(ComponentRegistry& _comp_reg)
{
	return true;
}

/// ------------------------------------------------------------------------------------------------

void Comp1_Task::run()
{
	/// --- Initialization	------------------------------------------------------------------------

	const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;

	uint32_t i = 0;

	trace_putc('1');
	trace_puts("ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`");
	trace_puts("abcdefghijklmnopqrstuvwxyz{|}~");
	trace_printf("val=%d\n", i++);
	trace_printf("%d\n", 1234);				//"1234"
	trace_printf("%6d,%3d%%\n", -200, 5);    //"  -200,  5%"
	trace_printf("%-6u\n", 100);			//"100   "
	trace_printf("%ld\n", 12345678L);		//"12345678"
	trace_printf("%04x\n", 0xA3);			//"00a3"
	trace_printf("%08LX\n", 0x123ABC);		//"00123ABC"
	trace_printf("%016b\n", 0x550F);		//"0101010100001111"
	trace_printf("%s\n", "String");			//"String"
	trace_printf("%-4s\n", "abc");			//"abc "
	trace_printf("%4s\n", "abc");			//" abc"
	trace_printf("%c\n", 'a');				//"a"
	trace_printf("%f\n", 10.0);            	//<xprintf lacks floating point support>
	vTaskDelay(xDelay);

	/// --- Infinite Loop	------------------------------------------------------------------------

	for (;;)
	{
		LED_Green.toggle();
		vTaskDelay(xDelay);
	}
}

/// === END OF FILE	================================================================================
