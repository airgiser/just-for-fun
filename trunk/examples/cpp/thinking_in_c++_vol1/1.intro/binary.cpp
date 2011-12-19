/*
 * \brief bit-manipulation operators.
 * \author arifox
 */

#include <iostream>
using std::cout;
using std::endl;

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

	unsigned char c = 0x5A;
	val_print("c = ", c);

	a &= c;
	val_print("a &= c; a = ", a);

	b |= c;
	val_print("b |= c; b = ", b);

	b ^= a;
	val_print("b ^= a; b = ", b);

	return 0;
}
