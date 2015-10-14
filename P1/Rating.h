#ifndef RATING_H
#define RATING_H
#include <string>
#include "Book.h"

using namespace std;

class Rating
{
	const int ZERO = 0;
	//Private Data Members

public:
	struct data
	{
		int rating;
		int isbn;
		int member;
	};

	data ratingData;
	//Constructors (Default and Initializing)
	Rating() {}

	Rating& Rating::operator= (const Rating &rhs);

	/*Rating& Rating::operator[] (int index)
	{
		Rating *ptr;
		ptr = ratingData.rating.getPtr;

		return ptr[index];
	}*/
	/*Rating(DArray<int> initIsbn, DArray<int> initRating, string initMember)
	{
		ratingData.isbn = initIsbn;
		ratingData.rating = initRating;
		ratingData.member = initMember;
	}*/

	//Rating &operator= (const Rating& rhs);

	//Mutator Functions
	void setRating(data ratingData);

	//Accessor Functions
	// ****************MOVE THESE*****************
	int getRating() const;
	void displayRatings(data ratingData) const;

	//Return an array of ISBN's of recomended books
	int* getRecomendations(data ratingData) const;

	//Rating File IO Functions
	void loadFile(ifstream ratings) const;
	void saveFile(ofstream &books);
};
#endif
