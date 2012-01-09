/*
 * \brief setjump() & longjump() demo. It isn't a good idea in C++.
 * \author airfox<airgis@163.com>
 */

#include <iostream>
#include <csetjmp>
using namespace std;

class Object
{
public:
    Object()
    {
        cout<<"Object()"<<endl;
    }

    ~Object()
    {
        cout<<"~Object()"<<endl;
    }
};

jmp_buf jbuf;

void foo()
{
    Object obj;
    for(int i = 0; i < 5; i++)
    {
        cout<<"This is foo()"<<endl;
    }

    longjmp(jbuf, 23);
}

int main()
{
    if(setjmp(jbuf) == 0)
    {
        cout<<"Let's test something."<<endl;
        foo();
    }
    else
    {
        cout<<"There is something wrong."<<endl;
    }
}
