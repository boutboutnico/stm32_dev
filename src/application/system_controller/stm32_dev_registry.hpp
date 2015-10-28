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
/// \file	stm32_dev_registry.hpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#ifndef APPLICATION_SYSTEM_CONTROLLER_STM32_DEV_REGISTRY_HPP_
#define APPLICATION_SYSTEM_CONTROLLER_STM32_DEV_REGISTRY_HPP_

/// === Includes	================================================================================

#include "femtin/core/system_controller/component_registry.hpp"

/// === Namespaces	================================================================================

namespace application
{

namespace system_controller
{
/// === Forward Declarations	====================================================================
/// === Enumerations	============================================================================

enum class Component_Name_e
	: uint8_t
	{
		Comp1 = 0,
	Comp2,
};

/// === Class Declarations	========================================================================

class STM32_Dev_Registry : public femtin::system_controller::Component_Registry
{
public:
	/// === Public Constants	====================================================================
	/// === Public Declarations	====================================================================

	STM32_Dev_Registry();

private:
	///	=== Private Constants	====================================================================
	/// === Private Declarations	================================================================
	/// === Private Attributes	====================================================================
};

/// === Inlines Definitions	========================================================================

///	=== Non-Members Definitions	====================================================================

/// ------------------------------------------------------------------------------------------------
}
}

#endif
/// === END OF FILE	================================================================================
