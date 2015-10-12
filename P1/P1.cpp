#include "stdafx.h"
#include "Book.h"
#include "Member.h"
#include "Rating.h"
#include <iostream>
#include <fstream>


using namespace std;


void readBooks(string bookTxt)
{
	string line;
	ifstream file(bookTxt);
	if (file.is_open())
	{
		while (!(file.eof()))
		{
			getline(file, line, ',');
			cout << line << '\n';
			getline(file, line, '\n');
			cout << line << '\n';
		}

		file.close();
	}
	else cout << "Error: Unable to open file";

}

int main()
{
	Book testBook(1999, "Testing It", "Please Work");

	DArray<Book> testArray1;

	testArray1.add(testBook);

	unsigned long long int pls = testArray1[0].getIsbn();

	cout << pls << endl;

	readBooks("books.txt");

	cin >> pls;





	return 0;
} 