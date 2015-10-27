///
/// \file	appli_conf.hpp
///	\brief	
///	\date	19/04/2015
/// \author	nb_work
///
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

const uint8_t COMPONENT_COUNT = 1;
const uint8_t COMPONENT_NAME_LEN_MAX = configMAX_TASK_NAME_LEN;

const UBaseType_t COMPONENT_REGISTRY_TASK_PRIO = (tskIDLE_PRIORITY + 4);
const uint16_t COMPONENT_REGISTRY_TASK_STACK_SIZE = (1024 / 4);
const femtin::String<COMPONENT_NAME_LEN_MAX> COMPONENT_REGISTRY_TASK_NAME("CompReg");

const UBaseType_t COMP1_TASK_PRIO = (tskIDLE_PRIORITY + 3);
const uint16_t COMP1_TASK_STACK_SIZE = (576 / 4);
const femtin::String<COMPONENT_NAME_LEN_MAX> COMP1_TASK_NAME("Comp1");

/// ------------------------------------------------------------------------------------------------
}

#endif	/// APPLICATION_APPLI_CONF_HPP_
/// === END OF FILE	================================================================================
