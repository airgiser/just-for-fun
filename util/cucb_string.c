/*!
 * Copyright (c) airfox 2011
 *
 * \file cucb_string.c
 * \brief string utility
 *
 * \author airfox <airgis@163.com>
 */

#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#elif defined(LINUX) || defined(UNIX)
#include <iconv.h>
#include <string.h>
#endif

#include <assert.h>
#include "cucb_string.h"


/* Buffer overfolw if the length of buffer dest 
 * is not long enough(because of strncpy used).
 */
char *str_substr(char *dest, const char *src, size_t start, size_t num)
{
    assert(dest != NULL && src != NULL);
    if((start + num) > strlen(src))
    {
        assert(0);
        return NULL;
    }

    strncpy(dest, src + start, num);

    dest[num] = '\0';
    return dest;
}

size_t str_find_first_of(const char *str, int character)
{
    size_t pos = -1;
    char *p = strchr(str, character);
    if(p != NULL)
    {
        pos = (p - str);
    }

    return pos;
}

size_t str_find_last_of(const char *str, int character)
{
    size_t pos = -1;
    char *p = strrchr(str, character);
    if(p != NULL)
    {
        pos = (p - str);
    }

    return pos;
}

size_t str_find_first_not_of(const char *str, int character)
{
    int i = 0;
    int len = strlen(str);
    while(i < len && str[i] == character)
    {
        i++;
    }

    return ((i == len) ? -1 : i);
}

size_t str_find_last_not_of(const char *str, int character)
{
    int i = strlen(str) - 1;
    while(i >= 0 && str[i] == character)
    {
        i--;
    }

    return i;
}

char *str_ltrim(char *str, char junk)
{
    size_t i = 0;
    size_t len = strlen(str);
    size_t pos = str_find_first_not_of(str, junk);
    
    if(pos == -1)
    {
        memset(str, 0, len);
    }

    if(pos != 0)
    {
        for(i = 0; i < len - pos; i++)
        {
            str[i] = str[pos + i];
        }
        memset(str + len - pos, 0, pos);
    }
    
    return str;
}

char *str_rtrim(char *str, char junk)
{
    size_t len = strlen(str);
    size_t pos = str_find_last_not_of(str, junk);

    if(pos == -1)
    {
        memset(str, 0, len);
    }
    memset(str + pos + 1, 0, len - pos - 1); 

    return str;
}

char *str_to_lower(char *str)
{
    size_t i = 0;
    size_t len = strlen(str);
    assert(str != NULL);

    for(i = 0; i < len; i++)
    {
        if(str[i] >='A' && str[i] <= 'Z')
        {
            str[i] += ('a' - 'A');
        }
    }

    return str;
}

char *str_to_upper(char *str)
{
    size_t i = 0;
    size_t len = strlen(str);
    assert(str != NULL);

    for(i = 0; i < len; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= ('a' - 'A');
        }
    }

    return str;
}

size_t str_find(const char *str, const char *substr)
{
    size_t pos = -1;
    char *p = strstr(str, substr);
    if(p != NULL)
    {
        pos = (p - str);
    }

    return pos;
}

int str_start_with(const char *source, const char *start)
{
    int i = 0;
    size_t sublen = strlen(start);

    assert(source != NULL && start != NULL);
    if(sublen > strlen(source))
    {
        return 0;
    }

    for(i = 0; i < sublen; i++)
    {
        if(source[i] != start[i])
        {
            return 0;
        }
    }

    return 1;
}

int str_end_with(const char *source, const char *end)
{
    int i = 0;
    int sublen = strlen(end);
    int pos = strlen(source) - sublen;

    assert(source != NULL && end != NULL);
    if(pos < 0)
    {
        return 0;
    }

    for(i = 0; i < sublen; i++)
    {
        if(source[i+pos] != end[i])
        {
            return 0;
        }
    }

    return 1;
}

size_t mb_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
    return mbstowcs(dest, src, maximum);
}

size_t wchar_to_mb(char *dest, const wchar_t *src, size_t maximum)
{
    return wcstombs(dest, src, maximum);
}

#if defined(LINUX) || defined(UNIX)
static size_t encoding_convert(const char *tocode, const char *fromcode, 
        char *destbuf, size_t destlen, 
        char *srcbuf, size_t srclen)
{
    size_t len = 0;
    iconv_t conv = iconv_open(tocode, fromcode);
    if(conv == NULL)
    {
        return -1;
    }

    memset(destbuf, 0, destlen);
    len = iconv(conv, &srcbuf, &srclen, &destbuf, &destlen);

    iconv_close(conv);

    return len;
}

size_t utf8_to_gb(char *destbuf, char *srcbuf, size_t maximum)
{
    size_t destlen = maximum;
    size_t srclen = strlen(srcbuf);
    return encoding_convert("euc-cn", "utf-8", 
            destbuf, destlen, srcbuf, srclen);
}

size_t gb_to_utf8(char *destbuf, char *srcbuf, size_t maximum)
{
    size_t destlen = maximum;
    size_t srclen = strlen(srcbuf);
    return encoding_convert("utf-8", "euc-cn",
            destbuf, destlen, srcbuf, srclen);
}
#endif

#if defined(WIN32) || defined(WINCE)
size_t ansi_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
    /* The return value of the below function includes
     * the NULL termination characters
     */
    int count = MultiByteToWideChar(/*CP_ACP*/936, 0, src, -1, dest, maximum);

    return count - 1;
}

size_t wchar_to_ansi(char *dest, const wchar_t *src, size_t maximum)
{
    int count = WideCharToMultiByte(/*CP_ACP*/936, 0, src, -1, dest, maximum, NULL, NULL);
    return count - 1;
}

size_t utf8_to_wchar(wchar_t *dest, const char *src, size_t maximum)
{
    int count = MultiByteToWideChar(CP_UTF8, 0, src, -1, dest, maximum);
    return count - 1;
}

size_t wchar_to_utf8(char *dest, wchar_t *src, size_t maximum)
{
    int count = WideCharToMultiByte(CP_UTF8, 0, src, -1, dest, maximum,
            NULL, NULL);
    return count - 1;
}
#endif
