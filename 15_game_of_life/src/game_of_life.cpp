#include "game_of_life.h"

int GameOfLife::rows = 0;
int GameOfLife::cols = 0;
char GameOfLife::liveChar = ' ';
char GameOfLife::deadChar = ' ';
std::vector<std::vector<bool>> GameOfLife::grid;

GameOfLife::GameOfLife(int rows, int cols, char liveChar, char deadChar) {
    GameOfLife::rows = rows;
    GameOfLife::cols = cols;
    GameOfLife::liveChar = liveChar;
    GameOfLife::deadChar = deadChar;
    GameOfLife::grid.resize(rows, std::vector<bool>(cols, false));
}

void GameOfLife::drawShape(Shape shape, int startX, int startY) {
    switch (shape) {
    case BLOCK:
        if (startX + 1 < rows && startY + 1 < cols) {
            grid[startX][startY] = true;
            grid[startX][startY + 1] = true;
            grid[startX + 1][startY] = true;
            grid[startX + 1][startY + 1] = true;
        }
        break;

    case BOAT:
        if (startX + 2 < rows && startY + 2 < cols) {
            grid[startX][startY + 1] = true;
            grid[startX + 1][startY] = true;
            grid[startX + 1][startY + 2] = true;
            grid[startX + 2][startY + 1] = true;
            grid[startX + 2][startY + 2] = true;
        }
        break;

    case BLINKER:
        if (startX < rows && startY + 2 < cols) {
            grid[startX][startY] = true;
            grid[startX][startY + 1] = true;
            grid[startX][startY + 2] = true;
        }
        break;

    case BEACON:
        if (startX + 3 < rows && startY + 3 < cols) {
            grid[startX][startY] = true;
            grid[startX][startY + 1] = true;
            grid[startX + 1][startY] = true;
            grid[startX + 1][startY + 1] = true;
            grid[startX + 2][startY + 2] = true;
            grid[startX + 2][startY + 3] = true;
            grid[startX + 3][startY + 2] = true;
            grid[startX + 3][startY + 3] = true;
        }
        break;

    case GLIDER:
        if (startX + 2 < rows && startY + 2 < cols) {
            grid[startX][startY + 1] = true;
            grid[startX + 1][startY + 2] = true;
            grid[startX + 2][startY] = true;
            grid[startX + 2][startY + 1] = true;
            grid[startX + 2][startY + 2] = true;
        }
        break;

    case PULSAR:
        if (startX + 2 < rows && startY + 2 < cols) {
            for (int i = -2; i <= 2; ++i) {
                grid[startX + i][startY - 1] = true;
                grid[startX + i][startY + 1] = true;
            }
            grid[startX - 1][startY - 2] = true;
            grid[startX + 1][startY - 2] = true;
            grid[startX - 1][startY + 2] = true;
            grid[startX + 1][startY + 2] = true;
        }
        break;

    case PULSAR_2:
        if (startX + 2 < rows && startY + 2 < cols) {
            for (int i = -2; i <= 2; ++i) {
                grid[startX - 1][startY + i] = true;
                grid[startX + 1][startY + i] = true;
            }
            grid[startX - 2][startY - 1] = true;
            grid[startX - 2][startY + 1] = true;
            grid[startX + 2][startY - 1] = true;
            grid[startX + 2][startY + 1] = true;
        }
        break;



    case PENTADECATHLON:
        if (startX + 2 < rows && startY + 1 < cols) {
            for (int i = -1; i <= 1; ++i) {
                grid[startX][startY + i] = true;
            }
            for (int i = -2; i <= 2; ++i) {
                grid[startX + i][startY] = true;
            }
            grid[startX - 2][startY - 1] = true;
            grid[startX - 2][startY + 1] = true;
            grid[startX + 2][startY - 1] = true;
            grid[startX + 2][startY + 1] = true;
        }
        break;

    default:
        std::cerr << "Unknown shape." << std::endl;
        break;
    }
}

void GameOfLife::displayGrid() {
    system("cls");
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col)
            std::cout << (grid[row][col] ? GameOfLife::liveChar : GameOfLife::deadChar);
        std::cout << std::endl;
    }
}

void GameOfLife::run(int generations, int duration) {
    for (int generation = 0; generation < generations; ++generation) {
        GameOfLife::displayGrid();
        GameOfLife::updateGrid();
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
        std::cout << "\033[H\033[J"; 
    }
}
void GameOfLife::updateGrid() {
    std::vector<std::vector<bool>> newGrid = grid;

    for (int i = 0; i < GameOfLife::rows; ++i) {
        for (int j = 0; j < GameOfLife::cols; ++j) {
            int liveNeighbors = GameOfLife::countLiveNeighbors(i, j);
            if (GameOfLife::grid[i][j]) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[i][j] = false;
                }
            }
            else {
                if (liveNeighbors == 3) {
                    newGrid[i][j] = true;
                }
            }
        }
    }

    grid = newGrid;
}

int GameOfLife::countLiveNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int newX = x + i;
            int newY = y + j;
            if (newX >= 0 && newX < GameOfLife::rows && newY >= 0 && newY < GameOfLife::cols) {
                count += GameOfLife::grid[newX][newY] ? 1 : 0;
            }
        }
    }
    return count;
}