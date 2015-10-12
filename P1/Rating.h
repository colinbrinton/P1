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
		int isbn, rating;
		string member;
	};

	data ratingData;
	//Constructors (Default and Initializing)
	Rating()
	{
		ratingData.isbn = ZERO;
		ratingData.rating = ZERO;
		ratingData.member = "";
	}
	Rating(int isbn, int rating, string member);

	//Mutator Functions
	void setRating(data ratingData);

	//Accessor Functions
	// ****************MOVE THESE*****************
	int getRating(data ratingData) const;
	void displayRatings(data ratingData) const;

	//Return an array of ISBN's of recomended books
	int* getRecomendations(data ratingData) const;

	//Rating File IO Functions
	void loadFile(ifstream ratings) const;
	void saveFile(ofstream &books);
};
#endif

