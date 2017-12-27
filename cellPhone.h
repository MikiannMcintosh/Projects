#ifndef cellPhone_H
#define cellPhone_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Contact
{
	string firstName;
	string lastName;
	string homeContactNumber;
	string mobileContactNumber;
	bool hasNext = false;
};

class cellPhone
{
	Contact contacts[100];
	string display;
	bool isOn = false;
	string currentCall;
	bool callActive;
	int contactCount(Contact contactArray[]);
	void showOutput();

public:
	cellPhone();
	bool newContact(string firstName, string lastName, string homeContactNumber, string mobileContactNumber);
	void dialContact(string fName, string lName);
	void displayContactNumberInformation(string number);
	void powerDown();
	bool getPowerState();
};

#endif
