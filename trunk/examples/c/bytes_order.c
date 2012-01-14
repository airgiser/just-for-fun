/*
 * \brief Code to print the byte representation of program objects.
 * \author arifox
 */
#include <stdio.h>
#include <string.h>

static void binary_print(unsigned char val)
{
    int i = 0;
    for(i = 7; i >= 0; i--)
    {
        // val & 10000000
        // ...
        // val & 00000001
        if(val & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

static void bytes_print(unsigned char *p, int len)
{
    int i = 0;
    
    for(i = 0; i < len; i++)
    {
        // print in hexadecimal with at least two digits.
        printf(" %.2x", p[i]);
    }
    printf("\n");

    for(i = 0; i < len; i++)
    {
        printf(" ");
        binary_print(p[i]);
    }

    printf("\n");
}

static void bytes_print_int(int x)
{
    bytes_print((unsigned char *)&x, sizeof(int));
}

static void bytes_print_float(float x)
{
    bytes_print((unsigned char *)&x, sizeof(float));
}

static void bytes_print_pointer(void *x)
{
    bytes_print((unsigned char *)&x, sizeof(void *));
}

/*
 * big endian or little endian
 */
static void bytes_print_test(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;

    printf("0x%x:\n", ival);
    bytes_print_int(ival);

    printf("%f:\n", fval);
    bytes_print_float(fval);

    printf("0x%x:\n", (int)pval);
    bytes_print_pointer(pval);
}

int main(int argc, char *argv[])
{
    int val = 0x10203040;
    bytes_print_test(val);

    char *str = "123ABC";
    bytes_print(str, strlen(str) + 1);

    return 0;
}
