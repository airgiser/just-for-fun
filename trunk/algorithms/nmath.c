/*!
 * Copyright (c) 2012 airfox
 *
 * \brief Some math algorithm.
 */
#include <stdio.h>
#include <assert.h>

int fibonacci(unsigned int n)
{
    assert(n != 0);

    if(n == 1 || n == 2)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[])
{
    int i = 0;

    for(i = 1; i < 10; ++i)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}
