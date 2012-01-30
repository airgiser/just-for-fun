/*
 * Copyright (c) airfox 2012.
 *
 * \brief A Example show how to use pointer to member function.
 */

#include <iostream>
using namespace std;

class Widget
{
public:
    Widget()
    {
        m_funcPtr[0] = &Widget::FuncA;
        m_funcPtr[1] = &Widget::FuncB;
        m_funcPtr[2] = &Widget::FuncC;
        m_funcPtr[3] = &Widget::FuncD;
    }

    void Run(int i, int param)
    {
        if(i >= 0 && i < count)
        {
            (this->*m_funcPtr[i])(param);
        }
    }

    int GetCount() const
    {
        return count;
    }

private:
    // Member functions.
    void FuncA(int) const
    {
        cout<<"Widget::FuncA()"<<endl;
    }

    void FuncB(int) const
    {
        cout<<"Widget::FuncB()"<<endl;
    }

    void FuncC(int) const
    {
        cout<<"Widget::FuncC()"<<endl;
    }

    void FuncD(int) const
    {
        cout<<"Widget::FuncD()"<<endl;
    }

private:
    // Member function array.
    const static int count = 4;
    typedef void (Widget::*FuncPtr)(int) const;
    FuncPtr m_funcPtr[count];
};

int main()
{
    Widget w;
    for(int i = 0; i < w.GetCount(); i++)
    {
        w.Run(i, 56);
    }

    return 0;
}
