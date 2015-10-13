//P1.cpp
#include "stdafx.h"
#include "Book.h"
#include "Member.h"
#include "Rating.h"
#include <iostream>
#include <fstream>
#include <sstream>

const int RATING_LENG = 1;

using namespace std;


DArray<Book> readBooks(string bookTxt)
{
	Book newBook;
	DArray<Book> bookArray;
	string line;
	ifstream file(bookTxt);
	int count = 0;

	if (file.is_open())
	{
		while (!(file.eof()))
		{
			getline(file, line, ',');
			newBook.bookData.author = line;
			getline(file, line, '\n');
			newBook.bookData.title = line;
			++count;
			newBook.bookData.year = 2004; //Place holder
			newBook.setIsbn(count);
			bookArray.add(newBook);

		}

		/*	for (int i = ZERO; i < 55; i++)
		{
		cout << bookArray[i].bookData.author << endl;
		cout << bookArray[i].bookData.title << endl;
		cout << bookArray[i].bookData.year << endl;
		cout << bookArray[i].bookData.isbn << endl;
		}*/


		file.close();
		return bookArray;
	}
	else cout << "Error: Unable to open file";

	return bookArray;

}

void readRatings(string ratingTxt)
{
	//DArray<Book> bookArray = books;
	Rating newRating;
	Member newMember;
	DArray<Rating> ratingArray;
	DArray<Member> memberArray;
	string line;
	ifstream file2(ratingTxt);
	int x;
	int count2 = ZERO;
	int count3 = ZERO;

	if (file2.is_open())
	{
		while (!file2.eof())
		{
			file2.clear();
			getline(file2, line);
			//cout << line << endl;
			newMember.memberData.name = line;
			++count2;
			newMember.memberData.account = count2;
			memberArray.add(newMember);
			//ratingArray.add(newRating);

			count3 = ZERO;
			while (file2 >> x)
			{
				newRating.ratingData.rating = x;
				++count3;
				newRating.ratingData.isbn = count3;
				newRating.ratingData.member = count2;
				ratingArray.add(newRating);
				//cout << x << " ";
			}

			file2.ignore();

			//remove hardcode
			//(!isalpha(line[ZERO])) || (line[ZERO] = '-')
			//while (file.peek() != '\n')
			//{									//remove hardcode
			//	char c[2];
			//	file.get(c, 2, '\n');
			//	x = c[1];
			//	if (x >= 0 && x <= 9)
			//	{
			//		newRating.ratingData.rating.add(x);
			//	}
			//	if (c[1] == '-')
			//	{
			//		int x = c[2];
			//		x *= -1;
			//		newRating.ratingData.rating.add(x);
			//	}
			//}

			//newRating.ratingData.isbn[2];

			//ratingArray.add(newRating);
		}
		file2.close();
	}
	else cout << "Error: Unable to open file";

	for (int i = ZERO; i < memberArray.getSize(); i++)
	{
		cout << memberArray[i].memberData.name << endl;
		cout << memberArray[i].memberData.account << endl;
	}

	for (int i = ZERO; i < ratingArray.getSize(); i++)
	{
		cout << ratingArray[i].ratingData.isbn << endl;
		cout << ratingArray[i].ratingData.member << endl;
		cout << ratingArray[i].ratingData.rating << endl;
	}
}

int main()
{
	DArray<Book> books = readBooks("books.txt");


	for (int i = ZERO; i < books.getSize(); i++)
	{
		cout << books[i].bookData.author << endl;
		cout << books[i].bookData.title << endl;
		cout << books[i].bookData.year << endl;
		cout << books[i].bookData.isbn << endl;
	}

	//cout << endl << endl << books.getSize();
	readRatings("ratings.txt");

	/*DArray<int> test;
	test[3];
	test.add(3);*/

	int wait;
	cin >> wait;

	return 0;
}