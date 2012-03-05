/*!
 * Copyright (C) airfox 2012.
 *
 * \brief a token parser.
 */

#ifndef UCB_PARSER_TOKEN_H
#define UCB_PARSER_TOKEN_H

#include "typedef.h"

UCB_BEGIN

typedef void (*TokenFunc)(void *context, int index, const char *token);

int parse_token(const char *text, const char *delims, TokenFunc func, 
        void *context);

UCB_END

#endif
