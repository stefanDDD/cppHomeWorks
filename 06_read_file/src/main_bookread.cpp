#include <iostream>
#include <string>
#include <vector>
#include <fstream>
/**
	Define a simple book.
*/
class Book
{
public:
	std::string name;
	std::string authors;

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};

/**
	Reads a vector of books from a text file.
	Note: the text file shall contain lines of text in pairs for the book name and authors
	E.g.
		BOOK 1
		AUTHOR 1
		BOOK 2
		AUTHOR 2
		BOOK 3
		AUTHOR 1, AUTHOR 2, AUTHOR 3
	@param file_name The name of the file to read from (must include path).
	@return Vector of books.
*/
std::vector<Book> readBooksFromTextFile(const std::string& file_name)
{
    std::vector<Book> results;
    std::ifstream file(file_name);

    //check if the file is not opened
    if (!file.is_open()) {
        std::cout << "Cannot open file: " << file_name << std::endl;
        return results;
    }

    std::string line;
    std::string currentBookName;
    std::string currentAuthors;

    //a loop for each line
    while (std::getline(file, line))
    {
        //check only for non empty lines
        if (!line.empty())
        {
            //check for books in the file
            if (line.find("BOOK") != std::string::npos)
            {
                //check for non empty book names and author names
                if (!currentBookName.empty() && !currentAuthors.empty())
                {
                    //if are books and authors display them
                    Book myBook;
                    myBook.name = currentBookName;
                    myBook.authors = currentAuthors;
                    results.emplace_back(myBook);
                }

                //clean the current book and author to get to the another
                currentBookName.clear();
                currentAuthors.clear();
            }
            //if line find author do nothing (need book first)
            else if (line.find("AUTHOR") != std::string::npos)
            {
            }

            else
            {
                //if name of the book is empty get over it
                if (currentBookName.empty())
                {
                    currentBookName = line;
                }
                else
                {
                    //if the author not empty display them in a 'list'
                    if (!currentAuthors.empty())
                    {
                        currentAuthors += ", ";
                    }
                    currentAuthors += line;
                }
            }
        }
    }

    // Add the last book in the file, if there is one
    if (!currentBookName.empty() && !currentAuthors.empty())
    {
        Book myBook;
        myBook.name = currentBookName;
        myBook.authors = currentAuthors;
        results.emplace_back(myBook);
    }

    file.close();

    return results;
}

int main()
{
	// Read a collection of books from a file.
	// Simple examples can be found everywhere.
	// E.g. https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c

	// Read the data
    std::string input_data = "../../src/ermahgerd_berks.txt";
    std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromTextFile(input_data);

	// Print the data
	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	return 0;
}