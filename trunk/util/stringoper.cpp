
/*!
 * Copyright (c) airfox 2011
 *
 * \file stringoper.cpp
 * \brief string operation
 *
 * \author airfox <airgis@163.com>
 */

#include "stringoper.h"
#include <cstring>
using namespace std;

namespace ucb
{
    string &ltrim(string &str, char junk)
    {
        string::size_type begin = str.find_first_not_of(junk);
        if(begin != string::npos)
        {
            str = str.substr(begin);
        }
        else
        {
            str = "";
        }

        return str;
    }

    string &rtrim(string &str, char junk)
    {
        string::size_type end = str.find_last_not_of(junk);
        if(end != string::npos)
        {
            str = str.substr(0, end + 1);
        }
        else
        {
            str = "";
        }

        return str;
    }

    string &trim(string &str, char junk)
    {
        return ltrim(rtrim(str, junk), junk);
    }

    string &ltrim(string &str, const string &junks)
    {
        string::size_type i = 0;
        string::size_type size = str.size();
        while(i < size && junks.find(text[i]) != string::npos)
        {
            ++i;
        }
        if(i > 0 && i != size)
        {
            str = str.substr(i);
        }
        if(i == size)
        {
            str = "";
        }

        return str;
    }

    string &rtrim(string &str, const string &junks)
    {
        string::size_type size = str.size();
        string::size_type i = size - 1;
        while(i >= 0 && junks.find(text[i]) != string::npos)
        {
            --i;
        }

        if(i < 0)
        {
            str = "";
        }
        else if(i != size - 1)
        {
            str = str.substr(0, i + 1);
        }

        return str;
    }

    string &trim(string &str, const string &junks)
    {
        return ltrim(rtrim(str, junks), junks);
    }
}
