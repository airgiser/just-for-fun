/*
 * \brief Output formating 
 * \author airfox
 */

#include <iostream>
using namespace std;

int main()
{
    // Number formatting in decimal,octal and hexadecimal.
    cout<<"This is a number: "<<15<<endl;
    cout<<"in decimal: "<<dec<<15<<endl;
    cout<<"in octal: "<<oct<<15<<endl;
    cout<<"in hex: "<<hex<<15<<endl;

    cout<<"This is a floating-point number: "<<3.14159<<endl;
    cout<<"This is non-printing char (escape) : "<<char(27)<<endl;

    return 0;
}
