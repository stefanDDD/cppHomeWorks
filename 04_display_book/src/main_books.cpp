#include <string.h>
#include <iostream>

// Define the maximum length for the name to use.
// Specify the length of characters in the content (Excluding the terminator).
#define MAX_NAME_LEN 20
#define MAX_TITLE_LEN 50
#define MAX_AUTHORS 5


//the author struct
struct Author
{
	//the max length of the name
	char name[MAX_NAME_LEN + 1];
	//set name of the author
	void setName(char nameToSet[MAX_NAME_LEN])
	{
		strncpy(name, nameToSet, MAX_NAME_LEN);
		// overwrite the last character
		name[MAX_NAME_LEN] = 0;
	}

	//print the name of the author
	void print()
	{
		std::cout << name << std::endl;
	}
};


//book struct
struct Book
{
	int id;
	char title[50];

	int numAuthors;

	//autor struct call
	Author authors[MAX_AUTHORS];

	//add author on the book struct
	void addAuthor(Author author)
	{
		//conditions to add authors only if the limits its not reached
		if (numAuthors < MAX_AUTHORS)
		{
			authors[numAuthors] = author;
			numAuthors++;
		}
		else
		{
			std::cout << "Maximum number of authors reached for this book." << std::endl;
		}
	}

	//print the details of the books
	void print()
	{
		std::cout << "\nBook #" << id << std::endl;
		std::cout << "------" << std::endl;
		std::cout << this->title << std::endl;

		//print the authors (with conditions, if the book has or not)
		if (numAuthors == 0)
		{
			std::cout << "No authors listed." << std::endl;
		}
		else
		{
			//print all of them if it has multiple authors
			std::cout << "Authors:" << std::endl;
			for (int i = 0; i < numAuthors; i++)
			{
				std::cout << "- " << authors[i].name << std::endl;
			}
		}
	}
};

//set the name of the book
void setBookName(Book& book, std::string name)
{
	strncpy(book.title, name.c_str(), MAX_TITLE_LEN);
}

int main()
{
	Book book1;
	Book book2;
	Book book3;
	Book book4;
	Author author;

	// Load the data into books
	book1.id = 1;
	book1.numAuthors = 0;
	setBookName(book1, u8"The origin of truth (nu există, nu o căutați)");
	author.setName("Gusti");
	book1.addAuthor(author);

	book2.id = 2;
	book2.numAuthors = 0;
	setBookName(book2, "Arhanghelul Raul");
	author.setName("Ovidiu Eftimie");
	book2.addAuthor(author);

	book3.id = 3;
	book3.numAuthors = 0;
	setBookName(book3, "Factfulness");
	author.setName("Hans Rosling");
	book3.addAuthor(author);

	author.setName("Ola Rosling");
	book3.addAuthor(author);
	
	author.setName("Anna Rosling Ronnlund");
	book3.addAuthor(author);

	//added book 4
	book4.id = 4;
	book4.numAuthors = 0;
	setBookName(book4, "Clean Architecture");
	author.setName("Robert C. Martin");
	book4.addAuthor(author);


	// Display the books
	book1.print();
	book2.print();
	book3.print();
	book4.print();
	return 0;
}