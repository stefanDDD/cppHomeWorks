#include <iostream>
#include <string>

//verify if the number is armstrong or not
bool isArmstrongNumber(int number)
{
	//original number stored in origNumber
	int origNumber = number;
	//result integer
	int result = 0;
	//last digit integer
	int last_digit = 0;

	//while number is not 0, the last digit is taken and its cube is calculated, then all cubes are being add in the result
	//the last digit its eliminated after each operation
	while (number != 0) {
		last_digit = number % 10;
		result += last_digit * last_digit * last_digit;
		number /= 10;
	}

	//if the result its equal with the original number the its armstrong, else its not
	return (result == origNumber);
}

//prints if the number is or not armstrong
void printIsArmstrong(int number)
{
	//prints Armstrong
	if (isArmstrongNumber(number))
	{
		std::cout << "Armstrong" << std::endl;
	}
	//prints NOT Armstrong
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
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
	// What is this program expected to do?
	// - Shows whether an argument is an armstrong number.
	// (what?)
	// -	An Armstrong number is a number that is equal to the sum of cubes of its digits.
	//		For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
	//		Let's try to understand why 153 is an Armstrong number:
	//			1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
	//
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  03_armstrong.exe 1		=> Output: Armstrong
	//		  03_armstrong.exe 2		=> Output: NOT Armstrong
	//		  03_armstrong.exe 			=> Output: No program arguments found.
	//		  03_armstrong.exe ABC		=> Undefined output (do whatever).
	//		  03_armstrong.exe 153		=> Output: Armstrong
	//		  03_armstrong.exe 154		=> Output: NOT Armstrong
	//

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	int readNumber = 0;
	// Get the first argument
	std::string argumentAsString = argv[1];
	//verify if the number is integer
	if (!isInteger(argumentAsString))
	{
		printf("Invalid argument: Not a valid integer.\n");
		return 0;
	}


	// TODO: read number / cast to integer
	//make the number integer
	number = std::stoi(argumentAsString);

	printIsArmstrong(readNumber);
	return 0;
}