/*
 * \brief A simple example about a character traits.
 * In order to make istring fully equivalent to string,
 * we'd have to create the other functions necessary to 
 * support the new istring type.
 *
 * \author airfox<airgis@163.com>
 */

#include "ichar_traits.h"
#include <string>
#include <iostream>
using namespace std;

typedef basic_string<char, ichar_traits, allocator<char> > istring;

int main()
{
    istring first = "this";
    istring second = "This";
    cout<<first.compare(second)<<endl;

    return 0;
} 
