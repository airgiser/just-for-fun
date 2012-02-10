/*!
 * \brief A deom about recursion.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compos(const char *str, char *dstr, unsigned int num)
{
    int i = 0;
    int len = strlen(str);

    for(i = 0; i < len; i++)
    {
        dstr[num] = str[i];
        dstr[num+1] = '\0';
        printf("%s\t", dstr);

        if(i < len - 1)
        {
            compos(str+i+1, dstr, num+1);
        }
    }
}

int main(int argc, char *argv[])
{
    char srcstr[] = "string";
    char *dstr = (char *)malloc(strlen(srcstr) + 1);
    compos(srcstr, dstr, 0);
    free(dstr);

    return 0;
}
