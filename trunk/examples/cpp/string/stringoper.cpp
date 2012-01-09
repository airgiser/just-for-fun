/*
 * \brief Operating on strings.
 * \author airfox
 */

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

static void str_size_and_capacity(const string &src)
{
    cout<<src<<endl;
    cout<<"Size = "<<src.size()<<endl;
    cout<<"Capacity = "<<src.capacity()<<endl;
}

static void str_insert_demo()
{
    string src("a simple string.");
    str_size_and_capacity(src);

    src.insert(0, "This is ");
    str_size_and_capacity(src);
    cout<<endl;
}

static void str_reserve_and_append_demo()
{
    string src("This is a simple string.");
    str_size_and_capacity(src);

    src.reserve(256);
    str_size_and_capacity(src);

    // add this to the end of src.
    src.append(" This is another string.");
    str_size_and_capacity(src);
    cout<<endl;
}

static void str_replace(string &src, 
        const string &orign, const string &newstr)
{
    int pos = src.find_first_of(orign);
    if(pos != string::npos)
    {
        src.replace(pos, orign.size(), newstr);
    }
}

static void str_replace_demo()
{
    string src("This is a string.");
    cout<<src<<endl;

    int pos = src.find("string");
    cout<<"The start position of \"string\" is: "<<pos<<endl;
    
    // insert tag befor "string".
    string tag("$tag$");
    src.insert(pos, tag + ' ');
    cout<<src<<endl;

    pos = src.find(tag);
    cout<<"The start position of "<<tag<<" is: "<<pos<<endl;

    // replace "$tag$" with "Simple"
    src.replace(pos, tag.size(), "demo");
    cout<<src<<endl;

    // use the function str_replace() defined above.
    str_replace(src, "demo", "simple");
    cout<<src<<endl;

    // write a "replacement" beyond the end of an existing char array.
    src.replace(src.size(), 4, "simple");
    cout<<src<<endl;

    cout<<endl;
}

// Replace one character with another character all in the string.
static void str_stl_replace_demo()
{
    string src("Look Look Look Look");
    cout<<src<<endl;

    // The STL replace() algorithm only works with single objects
    // (in this case, char objects), and will not perform replacements
    // of quoted char arrays or of string objects.
    replace(src.begin(), src.end(), 'L', 'H');
    cout<<src<<endl;

    cout<<endl;
}

// Concatenation using non-member overloaded operators.
static void str_concat_demo()
{
    string str1("This ");
    string str2("is a ");
    string str3("simple string.");

    str1 = str1 + str2;
    cout<<str1<<endl;

    str1 += str3;
    cout<<str1<<endl;

    str1 += str1[4] + str3 + str1[4] + "Done.";
    cout<<str1<<endl;
}

int main()
{
    str_insert_demo();
    str_reserve_and_append_demo();

    str_replace_demo();
    str_stl_replace_demo();

    str_concat_demo();

    return 0;    
}
