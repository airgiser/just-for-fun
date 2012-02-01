#include <stdio.h>

/* Init: *x = a *y = b */
/* Result: *x = b, *y = a */
void inplace_swap(int *x, int *y)
{
    /* Step 1: *x = a ^ b, *y = b */
    *x = *x ^ *y;

    /* Step 2: *x = a ^ b, *y = a ^ b ^ b = a */ 
    *y = *x ^ *y;
    
    /* Step 3: *x = a ^ b ^ a = b, *y = a*/
    *x = *x ^ *y;
}

int main(int argc, char *argv[])
{
    int a = 45;
    int b = 983;
    printf("a: %d b: %d\n", a, b);

    inplace_swap(&a, &b);
    printf("a: %d b: %d\n", a, b);

    return 0;
}
