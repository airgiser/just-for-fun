#include <iostream>
using namespace std;

// recursive template instantiation
template<unsigned int n>
struct Factorial
{
    enum{ value = n * Factorial<n-1>::value };
};

template<>
struct Factorial<0>
{
    enum{ value = 1 };
};

int main(int argc, char *argv[])
{
    cout<<Factorial<10>::value<<endl;
    return 0;
}
