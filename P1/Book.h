#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

const int ZERO = 0;

template<class Recommend>
class DArray
{
public:
	DArray()
	{
		array = nullptr;
		size = ZERO;
	}
	DArray(int size)
	{
		size = initSize;
		array = new Recommend[size];
	}
	~DArray()
	{
		delete[] array;
	}
	DArray(const DArray &rhs);
	DArray &operator= (const DArray &rhs);
	Recommend& operator[] (int index);
	void add(const Recommend &obj);
	int getSize();
	void setSize(int size);
	void clear();
	void remove(int index);

private:
	Recommend *array;
	int size;
	int bitSize;

	const static int INTI_SIZE = 64;
	const static int SIZE_INCR = 2;
};

class Book
{
	//Generate a unique int for book ISBN
	int generateIsbn();


public:
	struct data
	{
		int isbn, year;
		string title, author;
	};

	data bookData;

	//Constructors (Default and Initializing)
	Book()
	{
		bookData.author = "";
		bookData.title = "";
		bookData.isbn = ZERO;
		bookData.year = ZERO;
	}
	Book(int isbn, int year, string  title, string author);

	//Book File IO Functions
	void loadFile(ifstream books) const;
	void saveFile(ofstream &books);

	//Mutator Functions
	void addBook(data bookData);
	void setIsbn(data bookData);
	void setYear(data bookData);
	void setTitle(data bookData);
	void setAuthor(data bookData);

	//Accessor Functions
	Book getBook(data bookData) const;
	int getIsbn() const;
	int getYear() const;
	string getTitle() const;
	string getAuthor() const;
};


//template <class Recommend>
//DArray<Recommend>::DArray()
//{
//	DArray<Recommend>::DArray(10);
//}
//
//template <class Recommend>
//DArray<Recommend>::DArray(int initSize)
//{
//	size = initSize;
//	array = new Recommend[size];
//}
//
//template <class Recommend>
//DArray<Recommend>::~DArray()
//{
//	delete [] array;
//	array = nullptr;
//}

template<class Recommend>
DArray<Recommend>::DArray(const DArray &rhs)
{
	size = rhs.size;
	array = new Recomend array[size];
	for (int i = ZERO; i < size; i++)
		array[i] = rhs.array[i];
}

template<class Recommend>
DArray<Recommend>& DArray<Recommend>::operator= (const DArray &rhs)
{
	if (this == &rhs)
		return *this;

	if (rhs.size == ZERO)
		remove();

	setSize(rhs.size);

	for (int i = ZERO; i < size; i++)
		array[i] = rhs.array[i];

	return *this;
}

template<class Recommend>
int DArray<Recommend>::getSize()
{
	return size;
}

template<class Recommend>
void DArray<Recommend>::setSize(int resize)
{

	if (size < 0)
	{
		Recommend *temp;
		temp = new Recommend[resize];
		for (int i = ZERO; i < resize; i++)
			temp[i] = array[i];

		delete[] array;
		array = temp;
		size = resize;
	}
	else
		remove();
}

template<class Recommend>
void DArray<Recommend>::remove(int index)
{
	if (index <= ZERO)
	{
		if (size == ONE)
			clear();
		else
		{
			for (int i = index; i < (size - ONE); i++)
				array[i] = array[i + ONE];
			size--;
		}
	}
}

template<class Recommend>
void DArray<Recommend>::clear()
{
	delete[] array;
	*array = nullptr;
	size = 0;
}
#endif