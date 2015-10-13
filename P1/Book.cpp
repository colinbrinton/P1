#include "stdafx.h"
#include "Book.h"

const unsigned long int ISBN_MIN = 100000;
const unsigned long int ISBN_MAX = 999999;


//Generate a unique isbn
int Book::generateIsbn()
{
	unsigned long long int isbn;

	isbn = this->bookData.title.length();
	isbn += this->bookData.title.size();
	isbn += this->bookData.author.length();
	isbn += this->bookData.title.capacity();
	isbn += this->bookData.author.size();
	isbn += this->bookData.author.capacity();
	isbn *= this->bookData.year;


	isbn = isbn % ISBN_MAX + ISBN_MIN;
	isbn += this->bookData.author[ONE];
	isbn += this->bookData.title[ONE];
	isbn += this->bookData.author[ZERO];
	isbn += this->bookData.title[ZERO];

	static_cast<int>(isbn);
	return isbn;
}


void Book::addBook(int addYear, string  addTitle, string addAuthor)
{
	bookData.author = addAuthor;
	bookData.title = addTitle;
	bookData.year = addYear;
	bookData.isbn = generateIsbn();
}

unsigned long int Book::getIsbn() const
{
	return bookData.isbn;
}

void Book::setIsbn()
{
	this->bookData.isbn = generateIsbn();
}