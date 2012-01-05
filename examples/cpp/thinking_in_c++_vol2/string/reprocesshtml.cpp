/*
 * \brief Demo of the erase() member function.
 * \author airfox
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

static string &erase_tag(string &str, const char *tag)
{
    int pos = 0;
    while((pos = str.find(tag)) != string::npos)
    {
        str.erase(pos, strlen(tag));
    }

    return str;
}

string &erase_p_marks(string &str)
{
    erase_tag(str, "<P>");
    erase_tag(str, "<P STYLE=\"margin-bottom: 0cm\">");
    erase_tag(str, "</P>");

    return str;
}

void process_body(istream &fin, ostream &fout)
{
    fout<<"<PRE>";
    string strline;
    while(getline(fin, strline))
    {
        if(strline.find("</BODY>") != string::npos)
        {
            fout<<"</PRE>"<<endl;
            fout<<strline<<endl;
            return;
        }
        if(strline.find("<P") != string::npos)
        {
            fout<<"\n";
        }
        else
        {
            fout<<" ";
        }
        fout<<erase_p_marks(strline);
    }
}

int main()
{
    ifstream fin("input.html");
    ofstream fout("output.html");

    string strline;
    while(getline(fin, strline))
    {
        if(strline.find("<BODY") != string::npos)
        {
            fout<<strline<<endl;
            process_body(fin, fout);
        }
        fout<<strline<<endl;
    }
}
