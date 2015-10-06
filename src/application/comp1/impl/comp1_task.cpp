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
#include "femtin/iomanip.hpp"
#include "femtin/freeRTOS_wrapper/delay.hpp"
#include "femtin/freeRTOS_wrapper/direct_task_notification/direct_task_notification.hpp"
#include "appli_conf.hpp"
#include "led/led.hpp"
#include "trace/trace.hpp"

/// === Namespaces	================================================================================

using namespace os;
using namespace femtin;
using namespace femtin::os;
using namespace femtin::unit;
using namespace board::led;
using namespace board::mcu;
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

	const millisecond delay { 500 };

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

		char c = 'a';
		lcd_ << c << ' ' << 'c' << endl;
		task_delay(delay);

		const char* s = "coucou";
		char str[] = "salut ";
		lcd_ << s << ' ' << str << ' ' << "string" << endl;
		task_delay(delay);

		int8_t v_int8 = -12;
		uint8_t v_uint8 = 34;
		lcd_ << v_int8 << ' ' << v_uint8 << endl;
		task_delay(delay);

		int16_t v_int16 = -345;
		uint16_t v_uint16 = 456;
		lcd_ << v_int16 << ' ' << v_uint16 << endl;
		task_delay(delay);

		int32_t v_int32 = -71234;
		uint32_t v_uint32 = 86456;
		lcd_ << v_int32 << ' ' << v_uint32 << endl;
		task_delay(delay);

		lcd_ << ios_base::hex << v_uint16 << endl;
		lcd_ << ios_base::oct << v_uint16 << endl;
		lcd_ << ios_base::dec << v_uint16 << endl;
		task_delay(delay);

		lcd_ << width(4) << 43 << endl;
		task_delay(delay);

		lcd_ << xy(10, 2) << "10,2" << endl;
		task_delay(delay);

		lcd_ << row(3) << "row 3" << endl;
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
