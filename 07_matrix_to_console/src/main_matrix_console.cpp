#include <iostream>
#include <string>
#include <vector>

/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count;
	size_t line_count;
	std::vector<std::vector<char>> storage;

public: 
	//define of the matrix
	Matrix(size_t numColumnsX, size_t numLinesY)
		: column_count(numColumnsX), line_count(numLinesY) {
		storage.resize(numLinesY, std::vector<char>(numColumnsX, 0));
	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& data)
	{
		//check if the line in the correct range and data is not more than the value of the columns
		if (line_number >= 0 && line_number < line_count && data.size() <= column_count)
		{
			//store the date in the storage vector
			for (size_t i = 0; i < data.size(); ++i)
			{
				storage[line_number][i] = data[i];
			}
		}
		else
		{
			//else invalid size
			std::cout << "Invalid line number or data size." << std::endl;
		}
	}
	//OPTIONAL
	//char getCellXY(size_t x, size_t y, char cell_content)
	//{
	//	// TODO: add functionality
	//	return 0;
	//}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1                     
		 |       0,2                      
		 .                             
		 .                             
		 .                             
		 |       0, H-1     ...          W-1, H-1           
		 V

		 Height
	*/
	void setCellXY(size_t x, size_t y, char cell_content)
	{
		//checks if x is in the correct range (same for y)
		if (x >= 0 && x < column_count && y >= 0 && y < line_count)
		{
			//if yes storage is equal with the cell_content (this being the - )
			storage[y][x] = cell_content;
		}
		else
		{
			//else Invalid coordinates
			std::cout << "Invalid coordinates (x, y)." << std::endl;
		}
	}

	void print()
	{

		// TODO: add functionality
		// print all lines and columns
		for (size_t i = 0; i < line_count; ++i) {
			for (size_t j = 0; j < column_count; ++j) {
				std::cout << storage[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");

	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/
	matrix.setCellXY(2, 1, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellXY(3, 7, 'O');
	matrix.print();
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
---O---------------X
------------------X-
-----------------X--
*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellXY(3, 11, 'O');
	return 0;
}