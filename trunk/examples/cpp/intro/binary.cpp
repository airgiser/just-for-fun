/*
 * \brief bit-manipulation operators.
 * \author arifox
 */

#include <iostream>
using std::cout;
using std::endl;
static unsigned char left_rotation(unsigned char val)
{
    int highbit = 0;
    
    // val & 10000000
    if(val & 0x80)
    {
        highbit = 1;
    }

    // Left shift
    val <<= 1;

    // Rotate the high bit onto the bottom
    val |= highbit;

    return val;
}

static unsigned char right_rotation(unsigned char val)
{
    int lowbit = 0;
    if(val & 1)
    {
        lowbit = 1;
    }

    // Right shift
    val >>=1;

    // Rotate the low bit onto the top
    val |= (lowbit << 7);

    return val;
}

static void binary_print(const unsigned char val)
{
    int i = 0;
    for(i = 7; i >= 0; i--)
    {
        // val & 10000000
        // ...
        // val & 00000001
        if(val & (1 << i))
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
}

static inline void val_print(const char *pre, const unsigned char val)
{
    cout<<pre;
    binary_print(val);
    cout<<endl;
}

int main()
{
    unsigned char a = 45;
    unsigned char b = 98;
    val_print("a = ", a);
    val_print("b = ", b);

    val_print("~a = ", ~a);
    val_print("~b = ", ~b);

    val_print("a & b = ", (a & b));
    val_print("a | b = ", (a | b));
    val_print("a ^ b = ", (a ^ b));

    //
    unsigned char c = 0x5A;
    val_print("c = ", c);

    a &= c;
    val_print("a &= c; a = ", a);

    b |= c;
    val_print("b |= c; b = ", b);

    b ^= a;
    val_print("b ^= a; b = ", b);

    //
    val_print("right rotation; c = ", right_rotation(c));

    val_print("left rotation; c = ", left_rotation(c));

    //
    double dval = 1.0;
    cout<<dval<<endl;

    unsigned char *p = reinterpret_cast<unsigned char *>(&dval);
    int i = 0;
    for(i = sizeof(double) - 1; i > 0; i -= 2)
    {
        binary_print(p[i-1]);
        binary_print(p[i]);
    }

    return 0;
}
