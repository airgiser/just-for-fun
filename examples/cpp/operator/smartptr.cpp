/*
 * Copyright (c) airfox 2012.
 *
 * \brief A nested smart pointer
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Obj
{
public:
    void print()
    {
        cout<<i++<<endl;
    }

private:
    static int i;
};

int Obj::i = 11;

class ObjContainer
{
public:
    class SmartPointer;
    friend class SmartPointer;

    void add(Obj *obj)
    {
        m_objArray.push_back(obj);
    }

    SmartPointer begin()
    {
        return SmartPointer(*this);
    }

public:
    class SmartPointer
    {
    public:
        SmartPointer(ObjContainer &container) : m_container(container), 
            m_index(0)
        {
        }

        bool operator++()
        {
            ++m_index;
            if(m_index < m_container.m_objArray.size())
            {
                return true;
            }

            return false;
        }

        Obj *operator->()
        {
            if(m_index >=0 && m_index < m_container.m_objArray.size())
            {
                return m_container.m_objArray[m_index];
            }

            assert(false);
            return NULL;
        }
    private:
        ObjContainer &m_container;
        unsigned int m_index;
    };

private:
    vector<Obj *> m_objArray;
};

int main()
{
    const int num = 10;
    Obj objArray[num];

    ObjContainer container;
    for(int i = 0; i < num; i++)
    {
        container.add(&objArray[i]);
    }

    ObjContainer::SmartPointer ptr = container.begin();
    do
    {
        ptr->print();
    }while(++ptr);

    return 0;
}
