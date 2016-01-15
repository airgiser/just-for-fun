/*
 * Copyright (c) arifox 2012.
 *
 * \brief A memory check utility.
 */

#ifndef UCB_MEM_CHECK_H
#define UCB_MEM_CHECK_H

// For size_t
#include <cstddef>

// The new operator
void *operator new(std::size_t size, const char *file, long line);
void *operator new[](std::size_t size, const char *file, long line);
#define new new (__FILE__, __LINE__)

// Global flag
extern bool activeFlag;
#define MEMCHECK_ON() activeFlag = true
#define MEMCHECK_OFF() activeFlag = false

#endif // UCB_MEM_CHECK_H
