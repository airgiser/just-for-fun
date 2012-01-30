/*
 * Copyright (c) airfox 2012
 *
 * \brief Add line numbers.
 */

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Read content from file.
    ifstream fin("linenum.cpp");
    vector<string> content;
    if(fin)
    {
        string strLine;
        while(getline(fin, strLine))
        {
            content.push_back(strLine);
        }
        if(content.size() == 0)
        {
            return 0;
        }
    }

    int num = 0;
    const int width = static_cast<int>(log10(content.size())) + 1;
    for(int i = 0; i < content.size(); i++)
    {
        cout.setf(ios::right, ios::adjustfield);
        cout.width(width);
        cout<<++num<<")"<<content[i]<<endl;
    }
}
