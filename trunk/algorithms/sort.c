/*
 * Copyright (c) airfox 2011
 *
 * \file sort.c
 * \brief sort algorithms
 *
 * \author airfox <airgis@163.com>
 */

#include "sort.h"
#include <assert.h>

static void quick_sort_imp(void **data, size_t size, DataCompareFunc cmp)
{
    size_t left = 0;
    size_t right = size - 1;
    void *value = data[left];
    while(left < right)
    {
        while(cmp(data[right], value) >= 0 && right > left)
        {
            right--;
        }
        if(right != left)
        {
            data[left] = data[right];
            left++;
        }

        while(cmp(data[left], value) <= 0 && left < right)
        {
            left++;
        }
        
        if(left != right)
        {
            data[right] = data[left];
            right--;
        }
    }
    data[left] = value;

    if(left > 0)
    {
        quick_sort_imp(data, left, cmp);
    }
    if(size > left + 1)
    {
        quick_sort_imp(data + left + 1, size - left - 1, cmp);
    }

    return;
}

void quick_sort(void **array, size_t size, DataCompareFunc cmp)
{
    assert(array != NULL && size > 1);

    if(array != NULL && size > 1)
    {
        quick_sort_imp(array, size, cmp);
    }

    return;
}


