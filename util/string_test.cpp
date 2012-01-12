#include "stringoper.h"
#include <iostream>
using namespace std;
using namespace ucb;

inline void print(const string &str)
{
    cout<<"["<<str<<"]"<<"[size: "<<str.size()<<"]"<<endl;
}

void trim_demo()
{
    string str("   This is a simple string. \t   ");
    print(rtrim(str));
    print(ltrim(str));
    print(trim(str));

    string seqstr(20, 'N');
    print(seqstr);
    print(rtrim(seqstr, "N"));

    cout<<endl;
}

int main()
{
    trim_demo();

    string str("   This is a simple string. \t   ");
    print(replace(str, "s", "S"));
    print(replace_all(str, "i", "I"));

    print(to_upper(str));
    print(to_lower(str));
    cout<<icmp(to_upper(str), to_lower(str))<<endl;

    print(erase_tag(str, "."));

    return 0;
}
