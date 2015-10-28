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
/// \file	comp2_task.cpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#include "comp2_task.hpp"
using namespace application::comp2;

/// === Includes	================================================================================

#include "femtin/freeRTOS_wrapper/delay.hpp"
#include "appli_conf.hpp"
#include "bsp/trace_uart/trace_uart.hpp"

/// === Namespaces	================================================================================

using namespace femtin;
using namespace femtin::os;
using namespace board::mcu;

/// === Public Definitions	========================================================================

Comp2_Task::Comp2_Task()
		: Task(application::COMP2_TASK_NAME.c_str(), application::COMP2_TASK_STACK_SIZE,
				application::COMP2_TASK_PRIO)
{
	suspend();
}

/// ------------------------------------------------------------------------------------------------

bool Comp2_Task::initialize(femtin::system_controller::Component_Registry& _comp_reg)
{
	(void) _comp_reg;
	return true;
}

/// ------------------------------------------------------------------------------------------------

void Comp2_Task::run()
{
	for (;;)
	{
		trace << "[Comp2] I am alive" << endl;

		task_delay_until(unit::millisecond(5000));
	}
}

/// === END OF FILE	================================================================================
