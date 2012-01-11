/*!
 * Copyright (c) airfox 2011
 *
 * \file stringoper.h
 * \brief string operation
 *
 * \author airfox <airgis@163.com>
 */
#ifndef UCB_STRING_OPER_H
#define UCB_STRING_OPER_H

#include <string>

namespace ucb
{
    using std::string;

    //
    // Trim unwanted characters from string.
    //
    string &ltrim(string &str, char junk = ' ');
    string &rtrim(string &str, char junk = ' ');
    string &trim(string &str, char junk = ' ');

    string &ltrim(string &str, const string &junks);
    string &rtrim(string &str, const string &junks);
    string &trim(string &str, const string &junks);

    //
    // Convert character case
    //
    string &to_upper(string &str);
    string &to_lower(string &str);

    string get_upper(const string &str);
    string get_lower(const string &str);

    //
    // Replace all the sub string(orgin) in src string.
    //
    string &replace_all(string &src, const string &orgin, const string&newstr);

} // namespace

#endif// UCB_STRING_OPER_H
