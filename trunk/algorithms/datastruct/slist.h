/*!
 * Copyright (c) airfox 2012.
 *
 * \brief A single list.
 */

#ifndef UCB_ADT_SLIST_H
#define UCB_ADT_SLIST_H

#include "typedef.h"

UCB_BEGIN

struct _SList;
typedef struct _SList SList;

SList *slist_create(DataDestroyFunc destroy, void *context);

Ret slist_append(SList *thiz, void *data);
Ret slist_insert_after(SList *thiz, size_t index, void *data);
Ret slist_get_by_index(SList *thiz, size_t index, void **data);
Ret slist_set_by_index(SList *thiz, size_t index, void *data);
Ret slist_delete(SList *thiz, size_t index);

size_t slist_get_length(SList *thiz);
int slist_find(SList *thiz, DataCompareFunc cmp, void *data);
Ret slist_foreach(SList *thiz, DataVisitFunc visit, void *context);

void slis_destroy(SList *thiz);

UCB_END

#endif /* UCB_ADT_SLIST_H*/
