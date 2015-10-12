#include "stdafx.h"
#include "Book.h"
#include "Member.h"
#include "Rating.h"
#include <iostream>
#include <fstream>


using namespace std;


DArray<Book> readBooks(string bookTxt)
{
	DArray<Book> newArray;
	Book newBook;
	string line;
	ifstream file(bookTxt);
	if (file.is_open())
	{

		while (getline(file, line, ','))
		{
			newBook.bookData.author = line;
			getline(file, line, '\n');
			newBook.bookData.title = line;
			newBook.bookData.year = 2000; //fix later
			newBook.setIsbn();

			newArray.add(newBook);
		}

		file.close();
	}
	else cout << "Unable to open file";

	return newArray;

}

int main()
{
	Book testBook(1999, "Testing It", "Please Work");

	DArray<Book> testArray1;

	testArray1.add(testBook);

	unsigned long long int pls = testArray1[0].getIsbn();

	cout << pls;

	testArray1 = readBooks("books.txt");

	//testArray1[3].getAuthor

	cin >> pls;


	return 0;
} 