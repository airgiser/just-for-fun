/*
 * Copyright (c) arifox 2012.
 *
 * \brief A memory check utility.
 */

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <vector>
using namespace std;
#undef new

bool activeFlag = false;

namespace ucb
{

class MemCheck
{
public:
    struct MemInfo {
        void *ptr;
        const char *filename;
        long line;

        bool isFree;
    };

    MemCheck() {
    }

    ~MemCheck() {
        for (size_t i = 0; i < _memSet.size(); i++) {
            MemInfo &memInfo = _memSet[i];
            if (!_memSet[i].isFree) {
                printf("Memory leaked at: %p (file: %s line: %ld)\n", 
                        memInfo.ptr, memInfo.filename, memInfo.line);
            }
        }
    }

    void *allocate(size_t size, const char *file, long line) {
        void *p = malloc(size);
        if (activeFlag) {
            MemInfo memInfo;
            memInfo.ptr = p;
            memInfo.filename = file;
            memInfo.line = line;
            add(memInfo);
            
            printf("Allocated %u bytes at address %p (file: %s, line: %ld)\n", 
                    size, p, file, line);
        }
        return p;
    }

    void release(void *p) {
        if (find(p) >= 0) {
            free(p);
            del(p);
            printf("Release memory at address: %p\n", p);
        }
        else if (!p && activeFlag) {
            printf("Attempt to delete unknown pointer: %p\n", p);
        }
    }

private:

    int find(void *p) {
        for (size_t i = 0; i < _memSet.size(); i++) {
            if (_memSet[i].ptr == p) {
                return i;
            }
        }
        return -1;
    }

    void add(const MemInfo &info) {
        _memSet.push_back(info);
    }

    void del(void *ptr) {
        // Mark pointer as freed
        for(size_t i = 0; i < _memSet.size(); i++) {
            if(_memSet[i].ptr == ptr) {
                _memSet[i].isFree = true;
            }
        }
    }

private:
    vector<MemInfo> _memSet;
};

static MemCheck memCheck;

} // ucb namespace

void *operator new(size_t size, const char *file, long line)
{
    return ucb::memCheck.allocate(size, file, line);
}

void *operator new[](size_t size, const char *file, long line)
{
    return operator new(size, file, line);
}

void operator delete(void *p) {
    ucb::memCheck.release(p);
}

void operator delete[](void *p) {
    operator delete(p);
}

