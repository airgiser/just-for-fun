/*
 * Copyright (c) airfox 2012.
 *
 * \brief Overload operators.
 */
#ifndef UCB_BYTE_H
#define UCB_BYTE_H

class Byte
{
public:
    Byte(unsigned char val = 0);

public:
    const Byte &operator+() const
    {
        return *this;
    }

    const Byte operator-() const
    {
        return Byte(-m_val);
    }
    
    const Byte operator~() const
    {
        return Byte(~m_val);
    }

    Byte operator!() const
    {
        return Byte(!m_val);
    }

    Byte *operator&()
    {
        return this;
    }

    const Byte &operator++()
    {
        m_val++;
        return *this;
    }

    const Byte operator++(int)
    {
        Byte prev(m_val);
        m_val++;
        return prev;
    }

    const Byte &operator--()
    {
        m_val--;
        return *this;
    }

    const Byte operator--(int)
    {
        Byte prev(m_val);
        m_val--;
        return prev;
    }

private:
    unsigned char m_val;
};

#endif // UCB_BYTE_H
