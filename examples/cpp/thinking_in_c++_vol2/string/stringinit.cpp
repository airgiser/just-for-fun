/*
 * \brief Creating and Initializing C++ strings
 * \author aifox
 */
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

static void init_demo_one()
{
	// Create an empty string and 
	// defer initializing it with character data.
	string strone;

	// Initialize a string by passing a literal,
	// quoted character array as an argument to the constructor.
	string strtwo("some characters.");

	// Initialize a string using '='
	string strthree = "This is a simple string.";

	// Use one string to initialize another
	string strfour(strthree);

	cout<<"{"<<strone<<"}"<<endl;
	cout<<"{"<<strtwo<<"}"<<endl;
	cout<<"{"<<strthree<<"}"<<endl;
	cout<<"{"<<strfour<<"}"<<endl;

	return;
}

static void init_demo_two()
{
	string str1("This is the first string.");
	string str2("This is the second string.");
	string str3("This is the third string.");
	cout<<"str1: "<<str1<<endl;
	cout<<"str2: "<<str2<<endl;
	cout<<"str3: "<<str3<<endl;

	// Copy 7 characters starting at element 0 from the source.
	string str4(str1, 0, 7);
	string str5(str2, 8, 10);
	// Copy either 90 characters or eos
	// starting at element 0 from the source.
	string str6(str3, 8, 90);
	cout<<"str4: "<<str4<<endl;
	cout<<"str5: "<<str5<<endl;
	cout<<"str6: "<<str6<<endl;

	// Combine different source of initialization data using operator+.
	string str7 = "str7: " + str4 + " " + 
		// The string object's substr() member function 
		// copy 9 characters starting at element 8 from str1,
		// to create a substring.
		str1.substr(8, 9) + " " + str5 + " " + str6;
	cout<<str7<<endl;

	// A convenient way to duplicate a string.
	string str8 = str3.substr();
	cout<<"str8: "<<str8<<endl;

	return;
}

// Initialize a string use the string iterators.
// Treat a string like a container.
static void init_demo_three()
{
	string src("This is a simple string.");
	string dest(src.begin(), src.end());

	cout<<src<<endl;
	cout<<dest<<endl;

	return;
}

static void init_demo_error()
{
	// Error: no single char inits
	//string strone('a');
	
	// Error: no integer inits
	//string strtwo(0x12);
}

int main(int argc, char *argv[])
{
	init_demo_one();
	cout<<endl;

	init_demo_two();
	cout<<endl;

	init_demo_three();
	cout<<endl;

	return 0;
}
