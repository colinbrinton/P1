//P1.cpp
#include "stdafx.h"
#include "Book.h"
#include "Member.h"
#include "Rating.h"
#include <iostream>
#include <fstream>


using namespace std;


void readBooks(string bookTxt)
{
	Book newBook;
	DArray<Book> bookArray;
	string line;
	ifstream file(bookTxt);

	if (file.is_open())
	{
		while (!(file.eof()))
		{
			getline(file, line, ',');
			newBook.bookData.author = line;
			getline(file, line, '\n');
			newBook.bookData.title = line;
			newBook.bookData.year = 2004; //Place holder
			newBook.setIsbn();
			bookArray.add(newBook);

		}

		for (int i = ZERO; i < 55; i++)
		{
			cout << bookArray[i].bookData.author << endl;
			cout << bookArray[i].bookData.title << endl;
			cout << bookArray[i].bookData.year << endl;
			cout << bookArray[i].bookData.isbn << endl;
		}


		file.close();
	}
	else cout << "Error: Unable to open file";

}

int main()
{

	readBooks("books.txt");

	int wait;
	cin >> wait;

	return 0;
}