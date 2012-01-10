/*
 * \brief Comparing strings.
 * \author airfox
 */

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

int main()
{
    string strone("Where");
    string strtwo("When");

    // Runtime error.
    //char c = strone[5];
    // Throw an exception.
    try
    {
        char c = strone.at(5);
    }
    catch(out_of_range &error)
    {
        cout<<"An out of range exception occurred. "<<error.what()<<endl;
    }

    int i = 0;
    for(i = 0; i < strone.size() && i < strtwo.size(); i++)
    {
        if(strone[i] == strtwo[i])
        {
            cout<<strone[i]<<" "<<i<<endl;
        }
    }

    if(strone != strtwo)
    {
        cout<<"Strings are different: ";
        if(strone > strtwo)
        {
            cout<<strone<<" is > "<<strtwo<<endl;
        }
        else
        {
            cout<<strone<<" is < "<<strtwo<<endl;
        }
    }

    switch(strone.compare(strtwo))
    {
        case 0:
            {
                cout<<strone<<" and "<<strtwo<<"are lexically equal"<<endl;
                break;
            }
        case -1:
            {
                strone.swap(strtwo);
            }
        case 1:
            {
                cout<<strone<<" is lexically greate than "<<strtwo<<endl;
            }
    }

    int result = strone.compare(0, 2, strtwo, 0, 2);
    if(result == 0)
    {
            cout<<"The 0~2 characters of the two strings are equal."<<endl;
    }

    return 0;
}
