/*
 * \brief Using iterator.
 * \author airfox<airgis@163.com>
 */

#include <string>
#include <iostream>
using namespace std;

// Case insensitive compare function.
int string_cmp_insensitive(const string &strone, const string &strtwo)
{
    string::const_iterator iterone = strone.begin();
    string::const_iterator itertwo = strtwo.begin();

    while(iterone != strone.end() && itertwo != strtwo.end())
    {
        if(toupper(*iterone) != toupper(*itertwo))
        {
            // Report which was lexically greater.
            return (toupper(*iterone) < toupper(*itertwo)) ? -1 : 1;
        }

        iterone++;
        itertwo++;
    }

    // If they match up to the detected eos, say which was longer.
    return (strone.size() - strtwo.size());
}

// Demo of iterating in reverse.
// This function print a string in reverse.
void rprint(string &str)
{
    string::reverse_iterator riter = str.rbegin();
    while(riter != str.rend())
    {
        cout<<(*riter)<<" ";
        riter++;
    }
    cout<<endl;
}

int main()
{
    string strone("This");
    string strtwo("There");
    string strthree("This's");
    string strfour("this");

    cout<<"Compare "<<strone<<" with "<<strtwo<<": ";
    cout<<string_cmp_insensitive(strone, strtwo)<<endl;
    cout<<"Compare "<<strone<<" with "<<strthree<<": ";
    cout<<string_cmp_insensitive(strone, strthree)<<endl;
    cout<<"Compare "<<strone<<" with "<<strfour<<": ";
    cout<<string_cmp_insensitive(strone, strfour)<<endl;

    string str("987654321");
    rprint(str);

    return 0;
}
