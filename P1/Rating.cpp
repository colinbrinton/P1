#include "stdafx.h"
#include "Rating.h"

//Rating& Rating::operator= (const Rating& rhs)
//{
//	return *this;
//	/*if (this == &rhs)
//		return *this;
//
//	ratingData.isbn = rhs.ratingData.isbn;
//	ratingData.rating = rhs.ratingData.rating;
//	ratingData.member = rhs.ratingData.member;
//
//	return *this;*/
//}

int Rating::getRating() const
{
	return ratingData.rating;
}

Rating& Rating::operator= (const Rating &rhs)
{
	if (this == &rhs)
		return *this;

	//if (rhs.size == ZERO)
	//clear();
	ratingData.isbn = rhs.ratingData.isbn;
	ratingData.rating = rhs.ratingData.rating;
	ratingData.member = rhs.ratingData.member;

	return *this;
}