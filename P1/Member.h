#ifndef MEMBER_H
#define MEMBER_H
#include <string>
#include "Book.h"

using namespace std;

class Member
{
	//Private Data Members

public:

	struct data
	{
		string account, name;
	};

	data memberData;

	//Constructors (Default and Initializing)
	Member()
	{
		memberData.account = "";
		memberData.name = "";
	}
	Member(data memberData);

	//Mutator Functions
	void addMember(data memberData);
	void setMemberName(data memberData);
	void setMemberAccount(data memberData);

	//Used to set login state
	void memberLogin();
	void memberLogout();

	//Accessor Functions
	void getMember() const;
	void getLogin() const;
	void displayAccount();

	//Function to quit program
	void quit();
};

#endif