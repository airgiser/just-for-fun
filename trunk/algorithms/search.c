/*!
 * Copyright (c) airfox 2011
 *
 * \file search.c
 * \brief binary search algorithm
 *
 * \author airfox <airgis@163.com>
 */

#include "search.h"
#include <assert.h>

int binary_search(void **array, size_t size, void *data, DataCompareFunc cmp)
{
    int begin = 0;
    int mid = 0;
    int end = size - 1;
    int result = 0;

    assert(array != NULL && cmp != NULL);
    if(array == NULL || cmp == NULL)
    {
        return -1;
    }

    while(begin <= end)
    {
        mid = begin + ((end - begin)>>1);
        result = cmp(array[mid], data);

        if(result == 0)
        {
            return mid;
        }

        if(result > 0)
        {
            end = mid - 1;
        }

        if(result < 0)
        {
            begin = mid + 1;
        }
    }

    return -1;
}
