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
/// \file	comp1_task.cpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#include "comp1_task.hpp"
using namespace application::comp1;

/// === Includes	================================================================================

#include "appli_conf.hpp"
#include "demo/led/led_demo.hpp"
#include "demo/trace_uart/trace_uart_demo.hpp"
#include "demo/clcd_420b/clcd_demo.hpp"
#include "demo/joystick_thumb/joystick_demo.hpp"

/// === Namespaces	================================================================================
/// === Public Definitions	========================================================================

Comp1_Task::Comp1_Task()
		: Task(application::COMP1_TASK_NAME.c_str(), application::COMP1_TASK_STACK_SIZE,
				application::COMP1_TASK_PRIO)
{
	suspend();
}

/// ------------------------------------------------------------------------------------------------

bool Comp1_Task::initialize(femtin::system_controller::Component_Registry& _comp_reg)
{
	(void) _comp_reg;
	return true;
}

/// ------------------------------------------------------------------------------------------------

void Comp1_Task::run()
{
////	demo::led::led_demo();
////	demo::trace_uart::trace_uart_demo();
////	demo::clcd_420b::clcd_demo();
	demo::joystick::joystick_demo();
}

/// === END OF FILE	================================================================================
