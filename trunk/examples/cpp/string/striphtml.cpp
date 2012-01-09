/*
 * \brief Remove html tags and markers
 * \author airfox
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string &str_replace_all(string &str, const string &orign, const string &newstr)
{
    unsigned int pos = str.find(orign);
    while(pos != string::npos)
    {
        str.replace(pos, orign.size(), newstr);
        pos = str.find(orign);
    }

    return str;
}

string &str_strip_html_tag(string &str)
{
    while(true)
    {
        unsigned int left = str.find('<');
        unsigned int right = str.find('>');
        if(left == string::npos || right == string::npos)
        {
            break;
        }

        str = str.erase(left, right - left + 1);
    }

    str_replace_all(str, "&lt;", "<");
    str_replace_all(str, "&gt;", ">");
    str_replace_all(str, "&amp;", "&");
    str_replace_all(str, "&quot;", "\"");

    return str;
}
    
int main()
{
    ifstream fin("output.html");
    ofstream fout("output");

    const int size = 4096;
    char buf[size];
    while(fin.getline(buf, size))
    {
        string str(buf);
        fout<<str_strip_html_tag(str)<<endl;
    }

    return 0;
}
