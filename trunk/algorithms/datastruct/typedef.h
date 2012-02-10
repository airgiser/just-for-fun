/*!
 * Copyright (c) airfox 2012.
 *
 * \brief ADT typedef head file.
 */

#ifndef UCB_ADT_TYPEDEF_H
#define UCB_ADT_TYPEDEF_H

#include <stdlib.h>

typedef enum _Ret
{
    RET_OK,
    RET_FAIL,
    RET_OUT_OF_MEMORY,
    RET_INVALID_PARAM,
}Ret;

typedef Ret (*DataVisitFunc)(void *context, void *data);
typedef int (*DataCompareFunc)(void *context, void *data);
typedef void (*DataDestroyFunc)(void *context, void *data);

#ifdef __cplusplus
    #define UCB_BEGIN extern "C" {
    #define UCB_END }
#else
    #define UCB_BEGIN
    #define UCB_END
#endif /* __cplusplus*/

#endif /* UCB_ADT_TYPEDEF_H*/
