/*!
 * \brief problem 0-1 kitbag.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int nVal = 10;
static int sumVal = 12;
static char *gkitbag = NULL;

void calc(size_t n, size_t sum)
{
    int i = 0;
    if(sum < 1 || n < 1 || (n == 1 && sum != 1))
    {
        return;
    }

    if(n == sum)
    {
        gkitbag[n] = 1;
        for(i = 1; i <= nVal; i++)
        {
            if(gkitbag[i])
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        gkitbag[n] = 0;
    }

    // used n
    gkitbag[n] = 1;
    calc(n-1, sum-n);
    gkitbag[n] = 0;

    // not used n
    calc(n-1, sum);
}

int main(int argc, int argv[])
{
    size_t n = nVal;
    size_t sum = sumVal;
    gkitbag = (char *)malloc(n + 1);
    memset(gkitbag, 0, n + 1);

    if(n > sum)
    {
        n == sum;
    }
    calc(n, sum);
    free(gkitbag);

    return 0;
}
