/*
 * \breif Searching in string.
 * \author airfox
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

// find()
// Searches a string for a specified character or a group of characters and 
// returns the starting position of the first occurrence found or npos if no 
// match is found.(npos is a const of -1 and indicates that a search failed)
//
// find_first_of()
// Searches a target string and returns the position of the first match of
// any character in a specified group. If no match is found, it returns npos.
//
// find_last_of()
// Searches a target string and returns the position of the last mathc of any
// character in a specified group. If no match is found, it returns npos.
//
// find_first_not_of()
// Searches a target string and returns the position of the first element that
// doesn't math any character in a specified group.If no such element is found,
// it returns npos.
//
// find_last_not_of()
// Searches a target string and returns the position of the largest subscript
// that doesn't math any character in a specified group. If no such element is
// found, it returns npos.
//
// rfind()
// Searches a string from end to beginning for a specified character or group
// of characters and returns the starting position of the match if one is
// found. If no match is found, it returns npos.

// This function print all the prime number between 0~99.
static void str_find_prime_demo()
{
	// 'P' prime, 'N' not prime.
	string src(100, 'P');
	// 0 and 1 is not prime
	src.replace(0, 2, "NN");

	int i = 0;
	for(i = 2; i <= (src.size() / 2) - 1; i++)
	{
		int factor = 0;
		for(factor = 2; factor * i < src.size(); factor++)
		{
			src[factor * i] = 'N';
		}
	}
	cout<<src<<endl;

	cout<<"Prime: "<<endl;
	int pos = src.find('P');
	while(pos != string::npos)
	{
		cout<<pos<<" ";
		pos++;
		pos = src.find('P', pos);
	}

	// find_first_not_of() demo.
	cout<<endl<<"Not prime: "<<endl;
	pos = src.find_first_not_of('P');
	while(pos != string::npos)
	{
		cout<<pos<<" ";
		pos++;
		pos = src.find_first_not_of('P', pos);
	}

	cout<<endl<<endl;
}

// Find a group of characters in a string
static void str_find_demo()
{
	string somenames("airfox, airgis, AirGis, airjordan");
	string tofind("gis");
	cout<<tofind<<" occurred at: ";
	int pos = somenames.find(tofind);
	while(pos != string::npos)
	{
		cout<<pos<<" ";
		pos++;
		pos = somenames.find(tofind, pos);
	}
	cout<<endl<<endl;
}

string str_to_upper(const string &src);
string str_to_lower(const string &src);

// Find a group of characters insensitive in a string.
static void str_find_insensitive_demo()
{
	string somenames("airfox, airgis, AirGis, airjordan");
	cout<<somenames<<endl;
	cout<<str_to_upper(somenames)<<endl;
	somenames = str_to_lower(somenames);
	cout<<somenames<<endl;

	string tofind("gis");
	cout<<tofind<<" occurred at: ";
	int pos = somenames.find(tofind);
	while(pos != string::npos)
	{
		cout<<pos<<" ";
		pos++;
		pos = somenames.find(tofind, pos);
	}
	cout<<endl<<endl;
}

string str_to_upper(const string &src)
{
	int len = src.length();
	char *buf = new char[len];
	src.copy(buf, len);

	int i = 0;
	for(i = 0; i < len; i++)
	{
		buf[i] = toupper(buf[i]);
	}

	string dest(buf, len);
	delete buf;
	return dest;
}

string str_to_lower(const string &src)
{
	int len = src.length();
	char *buf = new char[len];
	src.copy(buf, len);

	int i = 0;
	for(i = 0; i < len; i++)
	{
		buf[i] = tolower(buf[i]);
	}

	string dest(buf, len);
	delete buf;
	return dest;
}

// Reverse the order of words in a string.
static void str_rfind_demo()
{
}

int main()
{
	str_find_prime_demo();
	str_find_demo();
	str_find_insensitive_demo();

	return 0;
}
