/*
 * Copyright (c) arifox 2012.
 *
 * \brief TODO: A memory check utility.
 */

#include "memcheck.h"
#include <vector>
using std::vector;

namespace
{

class MemCheck
{
public:
    struct MemInfo
    {
        void *ptr;
        const char *filename;
        long line;

        bool isFree;
    };

    void Add(const MemInfo &info)
    {
        m_memSet.push_bask(info);
    }

    void Del(void *ptr)
    {
        size_t i = 0;
        for(; i < m_memSet.size(); i++)
        {
            if(m_memSet[i].ptr == ptr)
            {
                m_memSet[i].isFree = true;
            }
        }
    }

private:
    static vector<MemInfo> m_memSet;
};

} // anonymous namespace

void *operator new(size_t, const char *file, long line)
{
    return NULL;
}

void *operator new[](size_t, const char *file, long line)
{
    return NULL;
}

