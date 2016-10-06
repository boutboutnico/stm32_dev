///
/// \file	femtin_hook.hpp
///	\brief	
///	\date	2 janv. 2016
/// \author	nb_work
///
#ifndef MAIN_FEMTIN_HOOK_HPP_
#define MAIN_FEMTIN_HOOK_HPP_

#ifdef FEMTIN_TRACE

/// === Includes

#include <cstddef>

/// === Public Declarations

//#ifdef __cplusplus
//extern "C"
//{
//#endif

void femtin_write(const char* _str, size_t _size);

//#ifdef __cplusplus
//}
//#endif

#endif

#endif
