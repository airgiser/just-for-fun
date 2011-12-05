/*!
 * \file cucb_typedef.h
 * \brief type definition
 *
 * \author airfox <airgis@163.com>
 */

#ifndef CUCB_TYPEDEF_H_
#define CUCB_TYPEDEF_H_

#include<stdlib.h>

typedef int (*DataCompareFunc)(void *context, void *data);

#ifdef __cplusplus
#define CUCB_BEGIN extern "C" {
#define CUCB_END }
#else
#define CUCB_BEGIN
#define CUCB_END
#endif/*__cplusplus*/

#endif/*CUCB_TYPEDEF_H_*/
