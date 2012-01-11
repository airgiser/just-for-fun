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

    // Trim unwanted characters from string.
    string ltrim(const string &str, const string &junks = " \t");
    string rtrim(const string &str, const string &junks = " \t");
    string trim(const string &str, const string &junks = " \t");

    // Convert character case
    string to_upper(const string &str);
    string to_lower(const string &str);

    // Compare insensitive
    int icmp(const string &first, const string &second);

    // Replace.
    string &replace(string &str, const string &origin, const string &newstr);
    string &replace_all(string &str, const string &origin, const string& newstr);

    // Erase
    string &erase_tag(string &str, const string &tag);

} // namespace

#endif// UCB_STRING_OPER_H
