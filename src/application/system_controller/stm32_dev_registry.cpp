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
/// \file	stm32_dev_registry.cpp
///	\brief	
///	\date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#include "stm32_dev_registry.hpp"
using namespace application::system_controller;

/// === Includes	================================================================================

#include "../comp1/impl/comp1_component.hpp"
#include "../comp2/impl/comp2_component.hpp"

/// === Namespaces	================================================================================
/// === Constants	================================================================================

const uint8_t Comp1_id = static_cast<uint8_t>(Component_Name_e::Comp1);
const uint8_t Comp2_id = static_cast<uint8_t>(Component_Name_e::Comp2);

/// === Public Definitions	========================================================================

STM32_Dev_Registry::STM32_Dev_Registry()
{
	static comp1::Comp1_Component comp1;
	static comp2::Comp2_Component comp2;

	components_[Comp1_id] = &comp1;
	components_[Comp2_id] = &comp2;
}

/// ------------------------------------------------------------------------------------------------
/// === Private Definitions	========================================================================
/// ------------------------------------------------------------------------------------------------
/// === END OF FILE	================================================================================
