#include <iostream>

//prints message
void printMessageFor(const char* name)
{
	//print a message that contains variable name
	std::cout << "Hello from [" << name << "]" << std::endl;
}

//use the printMessageFor function with a custom parameter (my name)
void printMessage()
{
	//I called the function with a custom parameter
	printMessageFor("Datcu Stefan-Madalin");
}

int main()
{
	//I called the function that displays the message
	printMessage();
}