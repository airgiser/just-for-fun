#include "search.h"
#include <assert.h>
#include <stdio.h>

int cmp_int(void *first, void *second)
{
    return (int)first - (int)second;
}

static void binary_search_test(size_t size)
{
    void **array = malloc(sizeof(void *) * size);
    int i = 0;
    for(i = 0; i < size; i++)
    {
        array[i] = (void *)i;
    }

    for(i = 0; i < size; i++)
    {
        assert(binary_search(array, size, (void *)i, cmp_int) == i);
    }

    free(array);

    return;
}

int main(int argc, char *argv[])
{
    printf("Start testing...\n");
    binary_search_test(1000);
    printf("Complete.\n");
    return 0;
}
