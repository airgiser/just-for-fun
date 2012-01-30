/*
 * Copyright (c) airfox 2012
 *
 * \brief operator->* and operator()
 */

#include <iostream>
using namespace std;

class Dog
{
public:
    typedef int (Dog::*PMF)(int) const;
    class FuncObject
    {
    public:
        // Save the object pointer and member pointer.
        FuncObject(Dog *obj, PMF func) : m_obj(obj), m_pFunc(func)
        {
        }

        // Make the call using the object pointer and member pointer.
        int operator()(int i) const
        {
            return (m_obj->*m_pFunc)(i);
        }
    private:
        Dog *m_obj;
        PMF m_pFunc;
    };

public:
    int Run(int i) const
    {
        cout<<"Running..."<<endl;
        return i;
    }

    int Sleep(int i) const
    {
        cout<<"ZZZ"<<endl;
        return i;
    }

    FuncObject operator->*(PMF func)
    {
        return FuncObject(this, func);
    }
};

int main()
{
    Dog obj;
    Dog::PMF func = &Dog::Run;
    cout<<(obj->*func)(1)<<endl;
    func = &Dog::Sleep;
    cout<<(obj->*func)(2)<<endl;

    return 1;
}
