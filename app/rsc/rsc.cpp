/*!
 * Copyright (c) airfox 2012
 *
 * \brief Double dispath demo.
 *  game object implementation.
 *
 * \author airfox<airgis@163.com>
 */
#include "rsc.h"
#include "rscoper.h"

int Rock::Play(GameObject &other)
{
    return other.GetOper()->PlayWith(*this);
}

RscOper *Rock::GetOper()
{
    static RockOper oper;
    return &oper;
}

int Scissors::Play(GameObject &other)
{
   return other.GetOper()->PlayWith(*this);
}

RscOper *Scissors::GetOper()
{
    static ScissorsOper oper;
    return &oper;
}

int Cloth::Play(GameObject &other)
{
   return other.GetOper()->PlayWith(*this);
} 

RscOper *Cloth::GetOper()
{
    static ClothOper oper;
    return &oper;
}
