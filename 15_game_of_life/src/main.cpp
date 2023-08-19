#include <iostream>
#include "game_of_life.h"

int main() {
    GameOfLife game(25, 50, '@', '`');

    game.drawShape(GameOfLife::BLOCK, 22, 25);
    game.drawShape(GameOfLife::BOAT, 10, 20);
    game.drawShape(GameOfLife::BLINKER, 10, 14);
    game.drawShape(GameOfLife::BEACON, 5, 5);
    game.drawShape(GameOfLife::GLIDER, 12, 5);
    game.drawShape(GameOfLife::GLIDER, 10, 50);
    game.drawShape(GameOfLife::PULSAR, 5, 30);
    game.drawShape(GameOfLife::PULSAR_2, 1, 15);
    game.drawShape(GameOfLife::PENTADECATHLON, 20, 12);

    game.displayGrid();
    std::cout << "Press ENTER to start" << std::endl;
    _fgetchar();
    game.run(200, 100); // duration measured in ticks/millisecond

    return 0;
}