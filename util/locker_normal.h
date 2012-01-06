/*!
 * Copyright (c) airfox 2011
 *
 * \file locker_normal.h
 * \brief a normal locker for win32 or linux platform
 *
 * \author airfox <airgis@163.com>
 */

#ifndef UCB_LOCKER_NORMAL_H
#define UCB_LOCKER_NORMAL_H

#include "typedef.h"
#include "locker.h"

UCB_BEGIN

Locker *locker_normal_create(void);

UCB_END

#endif/*UCB_LOCKER_NORMAL_H*/
