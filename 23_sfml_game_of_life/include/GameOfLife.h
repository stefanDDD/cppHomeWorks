#pragma once
#include <vector>

#include "Shape.h"

class GameOfLife {
private:
	int rows;
	int cols;
	const char aliveChar;
	const char deadChar;
	std::vector<std::vector<bool>> grid;

	int countLiveNeighbours(int x, int y);
	void updateGrid();

public:
	GameOfLife(int rows, int cols, char aliveChar = '#', char deadChar = '_');
	void randomInit();
	void displayGrid();
	void drawShape(Shape shape, int row, int col);
	void run(int ticks, int duration); // duration measured in ticks/milisecond
};
