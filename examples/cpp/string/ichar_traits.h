/*
 * \brief Creating the case insensitive character traits.
 * \author airfox<airgis@163.com>
 */
#ifndef ICHAR_TRAITS_H
#define ICHAR_TRAITS_H

#include <string>
#include <cctype>

struct ichar_traits : public std::char_traits<char>
{
    static bool eq(char first, char second)
    {
        return std::toupper(first) == std::toupper(second);
    }

    static bool ne(char first, char second)
    {
        return std::toupper(first) != std::toupper(second);
    }

    static bool lt(char first, char second)
    {
        return std::toupper(first) != std::toupper(second);
    }

    static int compare(const char *strone, 
            const char *strtwo, size_t n)
    {
        for(int i = 0; i < n; i++)
        {
            if(std::tolower(*strone) > std::tolower(*strtwo))
            {
                return 1;
            }
            if(std::tolower(*strone) < std::tolower(*strtwo))
            {
                return -1;
            }
            if(*strone == '\0' || *strtwo == '\0')
            {
                return 0;
            }

            strone++;
            strtwo++;
        }
        return 0;
    }

    static const char *find(const char *str, int n, char c)
    {
        while(n-- > 0 && std::toupper(*str) != std::toupper(c))
        {
            str++;
        }
        return str;
    }
}

#endif//ICHAR_TRAITS_H
