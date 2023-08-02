#include <iostream>

//I used argv[] for multiple params
int main(int argc, char* argv[])
{
	//if no params are added a message infrom the user
	if (argc == 1) {
		std::cout << "No params added!" << std::endl;
		return 1;
	}

	//display the params line by line
	for (int i = 0; i < 5; i++) {
		std::cout << argv[i] << std::endl;
	}
	return 0;
}