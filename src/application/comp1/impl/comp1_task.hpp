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
#include "drivers/clcd_420b.hpp"

/// === Namespaces	================================================================================

namespace application
{

namespace comp1
{

/// === Class Declarations	========================================================================

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"

class Comp1_Task : public os::Task
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

	board::mcu::CLCD_420B lcd_;
};

#pragma GCC diagnostic pop

/// === Inlines Definitions	========================================================================

/// ------------------------------------------------------------------------------------------------
}
}
#endif
/// === END OF FILE	================================================================================
