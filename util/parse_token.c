/*
 * Copyright (C) airfox 2012.
 *
 * \brief parse token string.
 */

#include <string.h>
#include <stdlib.h>
#include "parse_token.h"

typedef enum _TokenState
{
    TS_INIT,
    TS_IN,
    TS_OUT,
}TokenState;

#define IS_DELIM(c) (strchr(delims, c) != NULL)
int parse_token(const char *text, const char *delims, TokenFunc func, 
        void *context)
{
    TokenState state = TS_INIT;
    int count = 0;

    char *buffer = strdup(text);
    char *ptr = buffer;
    char *token = buffer;

    for(ptr = buffer; *ptr != '\0'; ptr++)
    {
        switch(state)
        {
            case TS_INIT:
            case TS_OUT:
            {
                if(!IS_DELIM(*ptr))
                {
                    /* start of a token.*/
                    token = ptr;
                    state = TS_IN;
                }
                break;
            }
            case TS_IN:
            {
                if(IS_DELIM(*ptr))
                {
                    /* end of a token.*/
                    *ptr = '\0';
                    func(context, count++, token);
                    state = TS_OUT;
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }

    if(state == TS_IN)
    {
        func(context, count++, token);
    }

    free(buffer);
    return count;
}
