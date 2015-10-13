#include "stdafx.h"
#include "Book.h"

const unsigned long int ISBN_MIN = 100000;
const unsigned long int ISBN_MAX = 999999;



void Book::addBook(int addYear, string  addTitle, string addAuthor)
{
	bookData.author = addAuthor;
	bookData.title = addTitle;
	bookData.year = addYear;
}

unsigned long int Book::getIsbn() const
{
	return bookData.isbn;
}

void Book::setIsbn(int count)
{
	int isbn = count;
	bookData.isbn = isbn;
}