/*
 * \brief Copy one file to anothre, a line at a time.
 * \author airfox
 */

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("Makefile");
	ofstream fout("Makefile.2");

	string str;
	string dest;
	while(getline(fin, str))
	{
		dest += str + '\n';
		fout<<str<<endl;
	}
	cout<<dest;

	return 0;
}
