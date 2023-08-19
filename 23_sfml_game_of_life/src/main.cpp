#include <iostream>

#include "GameOfLife.h"

int main() {
	GameOfLife game(25, 50, '@', '`');

	// Add initial patterns
	//game.randomInit();
	game.drawShape(BLOCK, 22, 25);
	game.drawShape(BOAT, 10, 20);
	game.drawShape(BLINKER, 10, 14);
	game.drawShape(BEACON, 5, 5);
	game.drawShape(GLIDER, 12, 5);
	game.drawShape(GLIDER, 10, 50);
	game.drawShape(PULSAR, 5, 30);
	game.drawShape(PULSAR_2, 1, 15);
	game.drawShape(PENTADECATHLON, 20, 12);

	game.displayGrid();
	std::cout << "Press ENTER to start" << std::endl;
	_fgetchar();
	game.run(200, 100); // duration measured in ticks/millisecond

	return 0;
}