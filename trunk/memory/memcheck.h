/*
 * Copyright (c) arifox 2012.
 *
 * \brief A memory check utility.
 */

#ifndef UCB_MEM_CHECK_H
#define UCB_MEM_CHECK_H

// For size_t
#include <cstddef>
using std::size_t;

void *operator new(size_t, const char *file, long line);
void *operator new[](size_t, const char *file, long line);

#define new new(__FILE__, __LINE__)

#endif // UCB_MEM_CHECK_H
