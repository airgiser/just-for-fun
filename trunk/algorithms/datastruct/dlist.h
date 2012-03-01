/*!
 * Copyright (c) airfox 2012.
 *
 * \brief dlist interface.
 */

#ifndef UCB_ADT_DLIST_H
#define UCB_ADT_DLIST_H

#include "typedef.h"
#include "locker.h"

UCB_BEGIN

struct _DList;
typedef struct _DList DList;

DList *dlist_create(DataDestroyFunc destroy, void *context, Locker *locker);

Ret dlist_append(DList *thiz, void *data);
Ret dlist_preappend(DList *thiz, void *data);
Ret dlist_insert(DList *thiz, size_t index, void *data);
Ret dlist_get_by_index(DList *thiz, size_t index, void **data);
Ret dlist_set_by_index(DList *thiz, size_t index, void *data);
Ret dlist_delete(DList *thiz, size_t index);

size_t dlist_get_length(DList *thiz);
int dlist_find(DList *thiz, DataCompareFunc cmp, void *data);
Ret dlist_foreach(DList *thiz, DataVisitFunc visit, void *context);

void dlist_destroy(DList *thiz);

UCB_END

#endif /* UCB_DLIST_H*/
