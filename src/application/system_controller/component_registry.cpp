///
/// \file	component_registry.cpp
///	\brief	
///	\date	05/05/2015
/// \author	nboutin
///

#include "component_registry.hpp"
using namespace application::system_controller;

/// === Includes	================================================================================

#include "femtin/freeRTOS_wrapper/delay.hpp"
#include "../appli_conf.hpp"
#include "../comp1/impl/comp1_component.hpp"
//#include "../tic_reader/impl/tic_reader_component.hpp"
//#include "../logger/impl/logger_component.hpp"

//#include "../trace/trace.hpp"
#include "bsp/trace_uart/trace_uart.hpp"

/// === Namespaces	================================================================================

using namespace femtin;
using namespace board::mcu;

/// === Constants	================================================================================

const uint8_t Comp1_id = static_cast<uint8_t>(ComponentName_e::Comp1);
//const uint8_t Logger = static_cast<uint8_t>(ComponentName_e::Logger);

/// === Public Definitions	========================================================================

ComponentRegistry::ComponentRegistry()
		: 	Task(application::COMPONENT_REGISTRY_TASK_NAME.c_str(),
					application::COMPONENT_REGISTRY_TASK_STACK_SIZE,
					application::COMPONENT_REGISTRY_TASK_PRIO),
			components_()
{
	static comp1::Comp1_Component comp1;
//	static logger::LoggerComponent logger;

	components_[Comp1_id] = &comp1;
//	components_[Logger] = &logger;
}

/// ------------------------------------------------------------------------------------------------

void ComponentRegistry::run()
{
	/// --- Initialization	------------------------------------------------------------------------

	trace << "==========\tStart\t==========" << endl;

	/// TODO test with for(IComponent* comp : components) ???
	for (uint8_t i = 0; i < COMPONENT_COUNT; i++)
	{
		components_[i]->initialize(*this) ?
				trace << "[" << components_[i]->name().c_str() << "]\tInitialized" << endl :
				trace << "[" << components_[i]->name().c_str() << "]\t!!! NOT initialized !!!"
						<< endl;
	}

	for (uint8_t i = 0; i < COMPONENT_COUNT; i++)
	{
		components_[i]->start() ?
				trace << "[" << components_[i]->name().c_str() << "]\tStarted " << ios_base::hex
						<< reinterpret_cast<uint32_t>(components_[i]->get_task().handle())
						<< ios_base::dec << endl :
				trace << "[" << components_[i]->name().c_str() << "]\t!!! NOT started !!!" << endl;
	}

	trace << Task::number_of_tasks() << " tasks are running" << endl;

	/// --- Infinite Loop	------------------------------------------------------------------------

	char buffer[40 * 4];
	femtin::Array<TaskStatus_t, 4> task_status;

	for (;;)
	{
		Task::list_custom(buffer, task_status);
		trace << "Name\tState\tPrio\tNum\tStack" << endl;
		trace << buffer << endl;

		femtin::os::task_delay_until(unit::second(10));
	}
}

/// ------------------------------------------------------------------------------------------------

//application::logger::ILogger* ComponentRegistry::APILogger()
//{
//	assert(components_[Logger] != NULL);
//	assert(components_[Logger]->getAPIService() != NULL);
//	return reinterpret_cast<application::logger::ILogger*>(components_[Logger]->getAPIService());
//}

/// === Private Definitions	========================================================================
/// ------------------------------------------------------------------------------------------------
/// === END OF FILE	================================================================================
