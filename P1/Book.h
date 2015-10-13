#ifndef BOOK_H
#define BOOK_H
#include <string>

using namespace std;

const int ZERO = 0;
const int ONE = 1;

template<class Recommend>
class DArray
{
private:
	Recommend *array;

public:

	int size;

	DArray()
	{
		size = ZERO;
		array = new Recommend[ONE];

	}

	DArray(int initSize)
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
	DArray &operator= (const Recommend &rhs);
	Recommend& operator[] (int index);
	void add(const Recommend &obj);
	int getSize();
	void setSize(int size);
	void clear();
	void remove(int index);
	void* getPtr();
};

class Book
{
	//Generate a unique int for book ISBN


public:
	struct data
	{
		unsigned long int isbn;
		int year;
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

	Book(int initYear, string  initTitle, string initAuthor)
	{
		bookData.author = initAuthor;
		bookData.title = initTitle;
		bookData.year = initYear;
	}

	//Book File IO Functions
	void loadFile(ifstream books) const;
	void saveFile(ofstream &books);

	//Mutator Functions
	void addBook(int addYear, string  addTitle, string addAuthor);
	void setIsbn(int count);
	void setYear(data bookData);
	void setTitle(data bookData);
	void setAuthor(data bookData);

	//Accessor Functions
	Book getBook(data bookData) const;
	unsigned long int getIsbn() const;
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

//template<class Recommend>
//DArray<Recommend>::DArray(const Recommend &rhs)
//{
//	if (size == 1)
//}

template<class Recommend>
DArray<Recommend>::DArray(const DArray &rhs)
{
	size = rhs.size;
	array = new Recommend[size];
	for (int i = ZERO; i < size; i++)
		array[i] = rhs.array[i];
}

template<class Recommend>
Recommend& DArray<Recommend>::operator[] (int index)
{
	return array[index];
}

template<class Recommend>
DArray<Recommend>& DArray<Recommend>::operator= (const DArray &rhs)
{
	if (this == &rhs)
		return *this;

	//if (rhs.size == ZERO)
	//clear();

	setSize(rhs.size);

	for (int i = ZERO; i < size; i++)
		array[i] = rhs.array[i];

	return *this;
}

template<class Recommend>
DArray<Recommend>& DArray<Recommend>::operator= (const Recommend &rhs)
{
	if (this == &rhs)
		return *this;

	array[size] = rhs;

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

	if (resize < 0)
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
		clear();
}

template<class Recommend>
void DArray<Recommend>::add(const Recommend &obj)
{
	/*if (size == ZERO)
	{
	array[ZERO] = obj;
	size++;
	}*/

	//else
	//{
	int newSize = (size + ONE);

	Recommend *temp;
	temp = new Recommend[newSize];

	for (int i = ZERO; i < (size); i++)
		temp[i] = array[i];

	temp[(newSize - ONE)] = obj;

	delete[] array;
	size = newSize;
	array = temp;

	//}
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
	size = 0;
}

template<class Recommend>
void* DArray<Recommend>::getPtr()
{
	return array;
}


#endif