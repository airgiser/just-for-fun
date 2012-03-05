#include <stdio.h>
#include "parse_token.h"


typedef void (*TokenFunc)(void *context, int index, const char *token);

static void print_token(void *context, int index, const char *token)
{
    printf("[%2d]: %s\n", index, token);
}

int main(int argc, char *argv[])
{
    const char *text = "This is a simple string, This is another string.";
    const char *tokenstr = "green,red,yellow,black,white,blue";
    printf("%s\n", text);
    parse_token(text, " ,.", print_token, NULL);
    printf("\n%s\n", tokenstr);
    parse_token(tokenstr, ",", print_token, NULL);
    return 0;
}

