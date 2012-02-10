/*!
 * Copyright (c) airfox 2012.
 *
 * \brief print all the prime number between 0~n
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_prime(size_t n)
{
    char *number = (char *)malloc(sizeof(char) * (n + 1));
    int i = 0;
    int factor = 0;
    //int maxfactor = (n+1)/2;
    int maxfactor = (int)sqrt(n + 1);

    memset(number, 1, n+1);
    number[0] = number[1] = 0;
    for(factor = 2; factor < maxfactor; factor++)
    {
        for(i = 2; factor * i < (n+1); i++)
        {
            number[factor * i] = 0;
        }
    }

    for(i = 0; i < n+1; i++)
    {
        if(number[i] == 1)
        {
            printf("%d ", i);
        }
    }

    free(number);
    return;
}

int main(int argc, char *argv[])
{
    print_prime(2000);
}
