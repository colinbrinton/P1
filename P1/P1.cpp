#include "stdafx.h"
#include "Book.h"
#include "Member.h"
#include "Rating.h"

int main()
{
	Book testBook(1999, "Testing It", "Please Work");

	DArray<Book> testArray1;

	testArray1.add(testBook);

	return 0;
} 