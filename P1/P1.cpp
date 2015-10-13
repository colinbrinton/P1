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

int getSimUser(int accnum, DArray<Book> b, DArray<Member> m, DArray<Rating> r);


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

void readRatings(string ratingTxt, DArray<Rating> &ratingArray, DArray<Member> &memberArray)
{
	//DArray<Book> bookArray = books;
	Rating newRating;
	Member newMember;
	//DArray<Rating> ratingArray;
	//DArray<Member> memberArray;



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

	/*for (int i = ZERO; i < memberArray.getSize(); i++)
	{
		cout << memberArray[i].memberData.name << endl;
		cout << memberArray[i].memberData.account << endl;
	}

	for (int i = ZERO; i < ratingArray.getSize(); i++)
	{
		cout << ratingArray[i].ratingData.isbn << endl;
		cout << ratingArray[i].ratingData.member << endl;
		cout << ratingArray[i].ratingData.rating << endl;
	}*/
}

int main()
{
	DArray<Book> books = readBooks("books.txt");
	DArray<Member> members;
	DArray<Rating> ratings;

	readRatings("ratings.txt", ratings, members);

	/*for (int i = ZERO; i < books.getSize(); i++)
	{
		cout << books[i].bookData.author << endl;
		cout << books[i].bookData.title << endl;
		cout << books[i].bookData.year << endl;
		cout << books[i].bookData.isbn << endl;
	}

	for (int i = ZERO; i < members.getSize(); i++)
	{
		cout << members[i].memberData.name << endl;
		cout << members[i].memberData.account << endl;
	}

	cout << endl;

	for (int i = ZERO; i < ratings.getSize(); i++)
	{
		cout << ratings[i].ratingData.isbn << endl;
		cout << ratings[i].ratingData.member << endl;
		cout << ratings[i].ratingData.rating << endl;
	}*/

	//cout << endl << endl << books.getSize();
	//readRatings("ratings.txt");

	/*DArray<int> test;
	test[3];
	test.add(3);*/
	int login;
	cout << "Please log in with your account number: ";
	cin >> login;

	int user = getSimUser(login, books, members, ratings);

	cout << endl << user;
	



	int wait;
	cin >> wait;

	return 0;
}

int getSimUser(int accnum, DArray<Book> b, DArray<Member> m, DArray<Rating> r)
{
	int user = accnum;
	int indexMin;
	int indexMax;
	int indexNum;
	int rateSize = (r.getSize() - ONE);
	int simFac = ZERO;
	int compat = ZERO;
	int compatUser;
	int totalUsers = (m.getSize() - ONE);

	int size = b.getSize();
	indexNum = (size - ONE);

	indexMin = (user * indexNum);
	indexMax = (indexMin + indexNum);

	for (int x = ZERO; x < (totalUsers - ONE); x++)
	{
		for (int y = indexMin; y <= indexMax; y++)
		{
			for (int i =(x * indexNum); i < (((indexNum + ONE) * x) + indexNum ) ; i++)
			{
				simFac += (r[i].getRating()) * (r[y].getRating());
			}
			if (simFac > compat)
			{
				compat = simFac;
				compatUser = x;
			}
		}
	}
	return compatUser;
}
