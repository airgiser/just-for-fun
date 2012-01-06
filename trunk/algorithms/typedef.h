/*!
 * Copyright (c) airfox 2011
 *
 * \file typedef.h
 * \brief type definition
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_TYPEDEF_H
#define UCB_TYPEDEF_H

#include<stdlib.h>

typedef int (*DataCompareFunc)(void *context, void *data);

#ifdef __cplusplus
#define UCB_BEGIN extern "C" {
#define UCB_END }
#else
#define UCB_BEGIN
#define UCB_END
#endif/*__cplusplus*/

#endif/*UCB_TYPEDEF_H*/
