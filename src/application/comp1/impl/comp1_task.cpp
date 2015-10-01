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

/// === Namespaces	================================================================================

using namespace os;
using namespace femtin::os;
using namespace femtin::unit;
using namespace board::led;
using namespace application::system_controller;
using namespace application::trace;

/// === Public Definitions	========================================================================

Comp1_Task::Comp1_Task()
		: 	Task(application::COMP1_TASK_NAME.c_str(), application::COMP1_TASK_STACK_SIZE,
					application::COMP1_TASK_PRIO),
			lcd_()
{
	suspend();
}

/// ------------------------------------------------------------------------------------------------

bool Comp1_Task::initialize(ComponentRegistry& _comp_reg)
{
	(void) _comp_reg;
	return lcd_.initialize();
}

/// ------------------------------------------------------------------------------------------------

void Comp1_Task::run()
{
	/// --- Initialization	------------------------------------------------------------------------

	const millisecond delay { 1000 };

	/// --- Infinite Loop	------------------------------------------------------------------------

	trace_printf("int8_t: %d\n", sizeof(int8_t));
	trace_printf("int16_t: %d\n", sizeof(int16_t));
	trace_printf("int32_t: %d\n", sizeof(int32_t));
	trace_printf("int: %d\n", sizeof(int));
	trace_printf("long: %d\n", sizeof(long));
	trace_printf("long long: %d\n", sizeof(long long));

	lcd_.clear();

	for (;;)
	{
		LED_Green.toggle();

		lcd_.clear();
//		lcd_.print("Les Chatons\n");
//		lcd_.print("Les lapins");
//		lcd_ << 'f';
//		lcd_ << "coucou";

		static uint16_t n = 0;

		lcd_.printf("n:%d test", n);

		lcd_.move_to_row(1);
		lcd_ << 'n' << ':' << n << " test";

		n += 10;
		task_delay(delay);

//		lcd_.backlight(false);
//		task_delay(delay);
//
//		lcd_.backlight(true);
//		task_delay(delay);
//
//		lcd_.cursor(false);
//		task_delay(delay);
//
//		lcd_.cursor(true);
//		task_delay(delay);
//
//		lcd_.home();
//		lcd_.print("Home");
//		task_delay(delay);
//
//		lcd_.cursor_xy(10, 2);
//		lcd_.print("10,2");
//		task_delay(delay);
//
//		lcd_.move_to_row(1);
//		lcd_.print("row 1");
//		task_delay(delay);
	}
}

/// === END OF FILE	================================================================================
