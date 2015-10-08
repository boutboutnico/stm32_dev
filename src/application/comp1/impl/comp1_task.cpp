///
/// \file	template.hpp
///	\brief
///	\date	dd/mm/yyyy
/// \author	author
///

#include "comp1_task.hpp"
using namespace application::comp1;

/// === Includes	================================================================================

#include "appli_conf.hpp"
#include "demo/led/led_demo.hpp"

/// === Namespaces	================================================================================
/// === Public Definitions	========================================================================

Comp1_Task::Comp1_Task()
		: Task(application::COMP1_TASK_NAME.c_str(), application::COMP1_TASK_STACK_SIZE,
				application::COMP1_TASK_PRIO)
{
	suspend();
}

/// ------------------------------------------------------------------------------------------------

bool Comp1_Task::initialize(application::system_controller::ComponentRegistry& _comp_reg)
{
	(void) _comp_reg;
	return true;
}

/// ------------------------------------------------------------------------------------------------

void Comp1_Task::run()
{
	demo::led::led_demo();
}

/// === END OF FILE	================================================================================
