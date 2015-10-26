///
/// \file	component_registry.cpp
///	\brief	
///	\date	05/05/2015
/// \author	nboutin
///

#include "component_registry.hpp"
using namespace application::system_controller;

/// === Includes	================================================================================

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
		: Task(application::COMPONENT_REGISTRY_TASK_NAME.c_str(),
				application::COMPONENT_REGISTRY_TASK_STACK_SIZE,
				application::COMPONENT_REGISTRY_TASK_PRIO)
{
	static comp1::Comp1_Component comp1;
//	static logger::LoggerComponent logger;

	components_[Comp1_id] = &comp1;
//	components_[Logger] = &logger;
}

/// ------------------------------------------------------------------------------------------------

void ComponentRegistry::run()
{
	const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;

	/// --- Initialization	------------------------------------------------------------------------

	trace << "==========\tStart\t==========" << endl;

	/// TODO test with for(IComponent* comp : components) ???
	for (uint8_t i = 0; i < COMPONENT_COUNT; i++)
	{
		components_[i]->initialize(*this) ?
//				trace_printf("[%s]\tInitialized\n", components_[i]->name().c_str()) :
//				trace_printf("[%s]\t!!! NOT initialized !!!\n", components_[i]->name().c_str());
				trace << "[" << components_[i]->name().c_str() << "]\tInitialized" << endl :
				trace << "[" << components_[i]->name().c_str() << "]\t!!! NOT initialized !!!"
						<< endl;
	}

	for (uint8_t i = 0; i < COMPONENT_COUNT; i++)
	{
		components_[i]->start() ?
//				trace_printf("[%s]\tStarted\n", components_[i]->name().c_str()) :
//				trace_printf("[%s]\t!!! NOT started !!!\n", components_[i]->name().c_str());
				trace << "[" << components_[i]->name().c_str() << "]\tStarted" << endl :
				trace << "[" << components_[i]->name().c_str() << "]\t!!! NOT started !!!" << endl;
	}

	/// --- Infinite Loop	------------------------------------------------------------------------

	for (;;)
	{
		vTaskDelay(xDelay);
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
