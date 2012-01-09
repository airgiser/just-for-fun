/*
 * \brief Convert a number(decimal, octal, hexadecimal).
 * \author airfox
 */

#include <iostream>
using namespace std;

static void format_num(int number)
{
    cout<<"Dec: "<<dec<<number<<endl;
    cout<<"Oct: 0"<<oct<<number<<endl;
    cout<<"Hex: 0x"<<hex<<number<<endl;
}

static void dec_conv()
{
    int number;
    cout<<"Please input a decimal number: ";
    cin>>number;

    format_num(number);
}

static void oct_conv()
{
    int number;
    cout<<"Please input a octal number: ";
    cin>>oct>>number;

    format_num(number);
}

static void hex_conv()
{
    int number;
    cout<<"Please input a hexadecimal number: ";
    cin>>hex>>number;

    format_num(number);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cout<<"Please add arguments: "
               "-d[decimal] -o[octal] -h[hex]"<<endl;

        return 0;
    }

    if(argv[1][1] == 'd')
    {
        dec_conv();
    }
    else if(argv[1][1] == 'o')
    {
        oct_conv();
    }
    else if(argv[1][1] == 'h')
    {
        hex_conv();
    }

    return 0;
}
