/*
 * Copyright airfox 2012
 *
 * \brief Overload operators
 */

#ifndef UCB_INTEGER_H
#define UCB_INTEGER_H

class Integer
{
public:
    Integer(int val = 0);

public:
    // TODO: member function is better than friend function.
    friend const Integer &operator+(const Integer &i);
    friend const Integer operator-(const Integer &i);

    friend const Integer operator~(const Integer &i);

    friend int operator!(const Integer &i);

    friend const Integer &operator++(Integer &i);
    friend const Integer operator++(Integer &i, int);
    friend const Integer &operator--(Integer &i);
    friend const Integer operator--(Integer &i, int);

public:

private:
    int m_val;
};

#endif // UCB_INTEGER_H
