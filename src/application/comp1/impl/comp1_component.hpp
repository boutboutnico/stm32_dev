///
/// \file	template.hpp
///	\brief	
///	\date	dd/mm/yyyy
/// \author	author
///
#ifndef APPLICATION_COMP1_IMPL_COMP1_COMPONENT_HPP_
#define APPLICATION_COMP1_IMPL_COMP1_COMPONENT_HPP_

/// === Includes	================================================================================

#include "system_controller/icomponent.hpp"

#include "comp1_service.hpp"
#include "comp1_task.hpp"

/// === Namespaces	================================================================================

namespace application
{

namespace comp1
{
/// === Forward Declarations	====================================================================
/// === Enumerations	============================================================================
/// === Class Declarations	========================================================================

class Comp1_Component : public system_controller::IComponent
{
public:
	/// === Constants	============================================================================
	/// === Public Declarations	====================================================================

	Comp1_Component();

	/// --- Component interface	--------------------------------------------------------------------

	virtual const femtin::String<COMPONENT_NAME_LEN_MAX>& name() const;

	virtual void* getAPIService();

	virtual bool initialize(system_controller::ComponentRegistry& _comp_reg);

	virtual bool start();

private:
	/// === Private Declarations	================================================================
	/// === Private Attributs	====================================================================

	Comp1_Service service_;
	Comp1_Task task_;

};

/// === Inlines Declarations	====================================================================

/// ------------------------------------------------------------------------------------------------
}/// name
}    /// sub_name

#endif	/// APPLICATION_COMP1_IMPL_COMP1_COMPONENT_HPP_
/// === END OF FILE	================================================================================
