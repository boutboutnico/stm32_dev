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
/// \file	comp1_task.hpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#ifndef APPLICATION_COMP1_IMPL_COMP1_TASK_HPP_
#define APPLICATION_COMP1_IMPL_COMP1_TASK_HPP_

/// === Includes	================================================================================

#include "femtin/freeRTOS_wrapper/task/task.hpp"
#include "femtin/core/system_controller/component_registry.hpp"

/// === Namespaces	================================================================================

namespace application
{
namespace comp1
{

/// === Class Declarations	========================================================================

class Comp1_Task : public femtin::os::Task
{
public:
	/// === Public Constants	====================================================================
	/// === Public Declarations	====================================================================

	Comp1_Task();

	bool initialize(femtin::system_controller::Component_Registry& _comp_reg);

	virtual void run();

private:
	/// === Private Constants	====================================================================
	/// === Private Declarations	================================================================
	/// === Private Attributes	====================================================================
};

/// === Inlines Definitions	========================================================================

/// ------------------------------------------------------------------------------------------------
}
}
#endif
/// === END OF FILE	================================================================================
