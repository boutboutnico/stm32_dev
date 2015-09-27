///
/// \file	template.cpp
///	\brief	
///	\date	dd/mm/yyyy
/// \author	author
///

#include "comp1_component.hpp"
using namespace application::comp1;

/// === Includes	================================================================================
/// === Namespaces	================================================================================

using namespace femtin;
using namespace application;
using namespace application::system_controller;

/// === Constants	================================================================================
/// === Public Definitions	========================================================================

Comp1_Component::Comp1_Component()
		: service_(), task_()
{

}

/// ------------------------------------------------------------------------------------------------

const String<COMPONENT_NAME_LEN_MAX>& Comp1_Component::name() const
{
	return COMP1_TASK_NAME;
}

/// ------------------------------------------------------------------------------------------------

void* Comp1_Component::getAPIService()
{
	return &service_;
}

/// ------------------------------------------------------------------------------------------------

bool Comp1_Component::initialize(ComponentRegistry& _comp_reg)
{
	bool b_result = task_.initialize(_comp_reg);

	return b_result;
}

/// ------------------------------------------------------------------------------------------------

bool Comp1_Component::start()
{
	task_.resume();

	return true;
}

/// ------------------------------------------------------------------------------------------------
/// === Private Definitions	========================================================================
/// ------------------------------------------------------------------------------------------------
/// === END OF FILE	================================================================================
