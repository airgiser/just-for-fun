/*
 * Copyright (c) airfox 2012.
 *
 * \brief Overload operators
 */
#include "integer.h"

Integer::Integer(int val) : m_val(val)
{
}

const Integer &operator+(const Integer &i)
{
    return i;
}

const Integer operator-(const Integer &i)
{
    return Integer(-i.m_val);
}

const Integer operator~(const Integer &i)
{
    return Integer(~i.m_val);
}

int operator!(const Integer &i)
{
    return !i.m_val;
}

const Integer &operator++(Integer &i)
{
    i.m_val++;
    return i;
}

const Integer operator++(Integer &i, int)
{
    Integer prev(i.m_val);
    i.m_val++;
    return prev;
}

const Integer &operator--(Integer &i)
{
    i.m_val--;
}

const Integer operator--(Integer &i, int)
{
    Integer prev(i.m_val);
    i.m_val--;
    return prev;
}

