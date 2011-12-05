/*!
 * \file cucb_locker.h
 * \brief interface definition of a locker
 *
 * \author airfox <airgis@163.com>
 */

#ifndef CUCB_LOCKER_H_
#define CUCB_LOCKER_H_

#include "cucb_typedef.h"
#include <stdlib.h>

CUCB_BEGIN

struct _Locker;
typedef struct _Locker Locker;

typedef int (*LockerLockFunc)(Locker *thiz);
typedef int (*LockerUnlockFunc)(Locker *thiz);
typedef void (*LockerDestroyFunc)(Locker *thiz);

typedef struct _Locker
{
	LockerLockFunc lock;
	LockerUnlockFunc unlock;
	LockerDestroyFunc destroy;

	char priv[0];
}Locker;

static inline int locker_lock(Locker *thiz)
{
	assert(thiz != NULL && thiz->lock != NULL);

	if(thiz != NULL && thiz->lock != NULL)
	{
		return thiz->lock(thiz);
	}

	return -1;
}

static inline int locker_unlock(Locker *thiz)
{
	assert(thiz != NULL && thiz->unlock != NULL);

	if(thiz != NULL && thiz->unlock != NULL)
	{
		return thiz->unlock(thiz);
	}

	return -1;
}

static inline void locker_destroy(Locker *thiz)
{
	assert(thiz != NULL && thiz->destroy != NULL);

	if(thiz != NULL && thiz->destroy != NULL)
	{
		thiz->destroy(thiz);
	}

	return;
}

CUCB_END

#endif
