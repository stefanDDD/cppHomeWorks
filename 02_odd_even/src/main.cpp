#include <stdio.h>

#include <iostream>
#include <string>


//verify the number (ODD or EVEN)
void printOddOrEven(int number)
{
	//if number is EVEN print EVEN
	if (number % 2 == 0)
	{
		printf("EVEN\n");
	}
	//else print ODD
	else
	{
		printf("ODD\n");
	}
}

//verify if the input number is integer
bool isInteger(const std::string& str)
{
	//if is empty or not fully with digits will return false
	if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
		return false;

	char* p;
	//converts  str to int (long int)
	strtol(str.c_str(), &p, 10);

	//return the p char
	return (*p == 0);
}

int main(int argc, char* argv[])
{
	int number = 0;

	// What is this program expected to do?
	// - Shows whether an argument is an ODD or EVEN number.
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  02_odd_even.exe 1		=> Output: ODD
	//		  02_odd_even.exe 2		=> Output: EVEN
	//		  02_odd_even.exe 		=> Output: No program arguments found.
	//		  02_odd_even.exe ABC   => Undefined output (do whatever).
	//		

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		printf("No program arguments found.\n");
		return 0;
	}

	// TODO(Gusti): i don't know why this doesn't work, but someone please FIX it.
	// --------------- start

	// Get the first argument
	std::string argumentAsString = argv[1];

	//verify if the number is integer
	if (!isInteger(argumentAsString))
	{
		printf("Invalid argument: Not a valid integer.\n");
		return 0;
	}

	//number = argv[1]; // No
	//should use atoi?
	// or std::stoi?

	// --------------- stop
	//make the number integer
	number = std::stoi(argumentAsString);

	//print the number
	printOddOrEven(number);

	return 0;
}