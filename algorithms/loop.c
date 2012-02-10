/*!
 * \brief A demo to print a charactor graphics by loop.
 */

#include <stdio.h>
void display(size_t n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char star = '*';
    char dot = '.';
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("%c", star);
            for(k = 0; k < i; k++)
            {
                printf("%c", dot);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    display(8);

    return 0;
}
