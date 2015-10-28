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
/// \file	appli_conf.hpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#ifndef APPLICATION_APPLI_CONF_HPP_
#define APPLICATION_APPLI_CONF_HPP_

/// === Includes	================================================================================

#include "femtin/freeRTOS_wrapper/task/task.hpp"
#include "femtin/string.hpp"
#include "FreeRTOSConfig.h"

/// === Namespaces	================================================================================

namespace application
{

/// === Public Declarations	========================================================================

const uint8_t COMPONENT_COUNT = 2;
const uint8_t COMPONENT_NAME_LEN_MAX = configMAX_TASK_NAME_LEN;

const uint8_t TASK_COUNT = 1	/// Component Registry Task
							+ COMPONENT_COUNT 		/// Application Component Tasks
							+ 1						/// IDLE Task used
							+ 1;					/// FreeRTOS Timer used

const UBaseType_t COMPONENT_REGISTRY_TASK_PRIO = 4;
const uint16_t COMPONENT_REGISTRY_TASK_STACK_SIZE = (1024 / 4);
const femtin::String<COMPONENT_NAME_LEN_MAX> COMPONENT_REGISTRY_TASK_NAME("CompReg");

const UBaseType_t COMP1_TASK_PRIO = 3;
const uint16_t COMP1_TASK_STACK_SIZE = (576 / 4);
const femtin::String<COMPONENT_NAME_LEN_MAX> COMP1_TASK_NAME("Comp1");

const UBaseType_t COMP2_TASK_PRIO = 2;
const uint16_t COMP2_TASK_STACK_SIZE = (512 / 4);
const femtin::String<COMPONENT_NAME_LEN_MAX> COMP2_TASK_NAME("Comp2");

/// Task priority 1 is reserved for Timer Service Task

/// ------------------------------------------------------------------------------------------------
}

#endif
/// === END OF FILE	================================================================================
