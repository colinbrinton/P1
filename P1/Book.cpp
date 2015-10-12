#include "stdafx.h"
#include "Book.h"

const unsigned long int ISBN_MIN = 100000;
const unsigned long int ISBN_MAX = 999999;


int Book::generateIsbn()
{
	unsigned long int isbn;

	isbn = this->bookData.title.length();
	isbn += this->bookData.title.size();
	isbn -= this->bookData.author.length();
	isbn += this->bookData.title.capacity();
	isbn -= this->bookData.author.size();
	isbn += this->bookData.title.max_size();
	isbn -= this->bookData.author.capacity();
	isbn += this->bookData.author.max_size();

	isbn = (isbn % ISBN_MAX) + ISBN_MIN;

	isbn =+ this->bookData.year;

	return isbn;
}


void Book::addBook(int addYear, string  addTitle, string addAuthor)
{
	bookData.author = addAuthor;
	bookData.title = addTitle;
	bookData.year = addYear;
	bookData.isbn = generateIsbn();
}