///
/// \file	template.hpp
///	\brief
///	\date	dd/mm/yyyy
/// \author	author
///

#ifndef APPLICATION_COMP1_IMPL_COMP1_TASK_HPP_
#define APPLICATION_COMP1_IMPL_COMP1_TASK_HPP_

/// === Includes	================================================================================

#include "femtin/freeRTOS_wrapper/task/task.hpp"
#include "system_controller/component_registry.hpp"

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

	bool initialize(system_controller::ComponentRegistry& _comp_reg);

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
