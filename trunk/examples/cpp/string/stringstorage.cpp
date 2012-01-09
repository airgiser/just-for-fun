/*
 * \brief In C++, individual string objects may or may not occupy unique
 *  physical region of memory, but if reference counting is used to avoid 
 *  storing duplicate copies of data, the individual objects must look and 
 *  act as though they do exclusively own uniqe regions of storage.
 *
 * \author airfox
 */
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    string str1 = "This is a simple string.";
    string::iterator it = str1.begin();

    // This may copy the first string to the second or
    // use reference couting to simulate a copy.
    string str2 = str1;

    // Either way, this statment may only modify the first string.
    *it = 't';

    cout<<"str1 = "<<str1<<endl;
    cout<<"str2 = "<<str2<<endl;

    return 0;
}
