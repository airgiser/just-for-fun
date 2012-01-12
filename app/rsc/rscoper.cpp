/*!
 * Copyright (c) airfox 2012
 *
 * \brief Double dispath demo.
 *  Operation implementation.
 *
 * \author airfox<airgis@163.com>
 */

#include "rscoper.h"
#include "rsc.h"

//
// RockOper
//
int RockOper::PlayWith(Rock &other)
{
    return 0;
}

int RockOper::PlayWith(Scissors &other)
{
    return 1;
}

int RockOper::PlayWith(Cloth &other)
{
    return -1;
}

//
// ScissorsOper
//
int ScissorsOper::PlayWith(Rock &other)
{
    return -1;
}

int ScissorsOper::PlayWith(Scissors &other)
{
    return 0;
}

int ScissorsOper::PlayWith(Cloth &other)
{
    return 1;
}

//
// ClothOper
//
int ClothOper::PlayWith(Rock &other)
{
    return 1;
}

int ClothOper::PlayWith(Scissors &other)
{
    return -1;
}

int ClothOper::PlayWith(Cloth &other)
{
    return 0;
}
