/*
 * \brief Copy an entire file into a vector of string
 * \author airfox
 */
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

static void print_content()
{
    vector<string> vec;
    ifstream fin("Makefile");
    string str;
    while(getline(fin, str))
    {
        vec.push_back(str);
    }

    int i = 0;
    for(i = 0; i < vec.size(); i++)
    {
        cout<<"Line"<<i<<": "<<vec[i]<<endl;
    }
}

static void print_words()
{
    vector<string> words;
    ifstream fin("Makefile");
    
    string word;
    while(fin>>word)
    {
        words.push_back(word);
    }

    int i = 0;
    for(i = 0; i < words.size(); i++)
    {
        cout<<words[i]<<endl;
    }
}

int main()
{
    print_content();
    cout<<endl;
    print_words();

    return 0;
}
