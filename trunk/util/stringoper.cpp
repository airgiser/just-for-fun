/*!
 * Copyright (c) airfox 2011
 *
 * \file stringoper.cpp
 * \brief Implementation of some useful string operation.
 *
 * \author airfox <airgis@163.com>
 */

#include "stringoper.h"
#include <cstring>
using namespace std;

namespace ucb
{
    //
    // Trim
    //
    string ltrim(const string &str, const string &junks)
    {
        if(str.size() == 0)
        {
            return str;
        }

        string::size_type begin = str.find_first_not_of(junks);
        if(begin == string::npos)
        {
            return "";
        }

        return string(str, begin, str.size() - begin);
    }

    string rtrim(const string &str, const string &junks)
    {
        if(str.size() == 0)
        {
            return str;
        }

        string::size_type end = str.find_last_not_of(junks);
        if(end == string::npos)
        {
            return "";
        }

        return string(str, 0, end + 1);
    }

    string trim(const string &str, const string &junks)
    {
        if(str.size() == 0)
        {
            return str;
        }

        string::size_type begin = str.find_first_not_of(junks);
        string::size_type end = str.find_last_not_of(junks);
        if(begin == string::npos || end == string::npos)
        {
            return "";
        }

        return string(str, begin, end - begin + 1);
    }

    //
    // Case convert
    //
    string to_upper(const string &str)
    {
        string::size_type i = 0;
        string::size_type size = str.size();
        string dest(str);

        for(i = 0; i < size; i++)
        {
            dest[i] = toupper(dest[i]);
        }

        return dest;
    }

    string to_lower(const string &str)
    {
        string::size_type i = 0;
        string::size_type size = str.size();
        string dest(str);

        for(i = 0; i < size; i++)
        {
            dest[i] = tolower(dest[i]);
        }

        return dest;
    }

    int icmp(const string &first, const string &second)
    {
        string::const_iterator iterfirst = first.begin();
        string::const_iterator itersecond = second.begin();

        while(iterfirst != first.end() && itersecond != second.end())
        {
            if(toupper(*iterfirst) != toupper(*itersecond))
            {
                return (toupper(*iterfirst) < toupper(*itersecond));
            }

            iterfirst++;
            itersecond++;
        }

        return (first.size() - second.size());
    }

    //
    // Replace
    //
    string &replace(string &str, const string &origin, const string &newstr)
    {
        string::size_type pos = str.find(origin);
        if(pos != string::npos)
        {
            str.replace(pos, origin.size(), newstr);
        }

        return str;
    }

    string &replace_all(string &str, const string &origin, const string& newstr)
    {
        string::size_type pos = str.find(origin);
        while(pos != string::npos)
        {
            str.replace(pos, origin.size(), newstr);
            pos = str.find(origin);
        }

        return str;
    }

    //
    // Erase
    //
    string &erase_tag(string &str, const string &tag)
    {
        string::size_type pos = 0;
        string::size_type size = tag.size();
        while((pos = str.find(tag)) != string::npos)
        {
            str.erase(pos, size);
        }

        return str;
    }
}
