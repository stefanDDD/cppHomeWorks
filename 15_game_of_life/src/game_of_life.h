#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class GameOfLife {

private:


public:
	enum Shape {
		BLOCK,
		BOAT,
		BLINKER,
		BEACON,
		GLIDER,
		PULSAR,
		PULSAR_2,
		PENTADECATHLON
	};
	static int rows;
	static int cols;
	static char liveChar;
	static char deadChar;
	static std::vector<std::vector<bool>> grid;

	GameOfLife(int rows, int cols, char liveChar, char deadChar);

	static void displayGrid();
	static void run(int generations, int duration);
	static void updateGrid();
	static int countLiveNeighbors(int x, int y);
	static void drawShape(Shape shape, int startX, int startY);

};