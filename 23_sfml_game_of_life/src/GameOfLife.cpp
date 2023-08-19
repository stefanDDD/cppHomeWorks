#include "GameOfLife.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

GameOfLife::GameOfLife(int rows, int cols, char aliveChar, char deadChar) : aliveChar(aliveChar), deadChar(deadChar) {
	this->rows = rows;
	this->cols = cols;
	grid.resize(rows, std::vector<bool>(cols, false));
}

void GameOfLife::randomInit() {
	// set a seed for getting a random value
	srand(time(nullptr));
	for (int row = 0; row < rows; ++row)
		for (int col = 0; col < cols; ++col)
			grid[row][col] = rand() % 2; // we'll get 0 (false) for even numbers and 1 (true) for odd numbers
}

void GameOfLife::displayGrid() {
	system("cls");
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col)
			std::cout << (grid[row][col] ? aliveChar : deadChar);
		std::cout << std::endl;
	}
}

int GameOfLife::countLiveNeighbours(int x, int y) {
	int count = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			int newX = x + i;
			int newY = y + j;
			// exclude the central cell and the cells that are out of bounds
			if (!(i == 0 && j == 0) && newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
				count += grid[newX][newY];
			}
		}
	}
	return count;
}

void GameOfLife::updateGrid() {
	std::vector<std::vector<bool>> newGrid = grid;

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j) {
			int liveNeighbours = countLiveNeighbours(i, j);
			if (grid[i][j] == true && (liveNeighbours < 2 || liveNeighbours > 3))
				newGrid[i][j] = false;
			else if (grid[i][j] == false && liveNeighbours == 3)
				newGrid[i][j] = true;
		}
	grid = newGrid;
}

void GameOfLife::run(int ticks, int duration) {
	if (ticks <= 0) {
		std::cout << "Invalid tick count" << std::endl;
		return;
	}

	for (int t = 1; t <= ticks; ++t) {
		displayGrid();
		updateGrid();
		std::cout << std::endl << t << " / " << ticks << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(duration));
	}
}


void GameOfLife::drawShape(Shape shape, int row, int col) {
	if (row < 0 || col < 0) {
		std::cout << "Invalid coordinate" << std::endl;
		return;
	}

	std::vector<std::vector<bool>> selectedShape = getShape(shape);

	int shapeRows = selectedShape.size();
	int shapeCols = selectedShape[0].size();

	// Ensure the shape fits within the grid boundaries
	int endX = std::min(row + shapeRows, rows);
	int endY = std::min(col + shapeCols, cols);

	for (int i = 0; i < shapeRows && row + i < endX; ++i) {
		for (int j = 0; j < shapeCols && col + j < endY; ++j) {
			grid[row + i][col + j] = selectedShape[i][j];
		}
	}
}
