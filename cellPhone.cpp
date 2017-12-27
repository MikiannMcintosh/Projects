#include <iostream>
#include <string>
#include "cellPhone.h"
using namespace std;

cellPhone::cellPhone()
{
    cellPhone::isOn = true;
}

void cellPhone::showOutput()
{
    cout << display << endl;
}

int cellPhone::contactCount(Contact contactArray[])
{
    int index;
    for (index = 0; index < 100; index++)
    {
        if (!contactArray[index].hasNext)
            return index + 1;
    }
    return 100;
}

bool cellPhone::newContact(string firstName, string lastName, string homeContactNumber, string mobileContactNumber)
{
    int currentIndex = cellPhone::contactCount(contacts);
    if (currentIndex == 100)
        return false;
    else
    {
        cellPhone::contacts[currentIndex].firstName = firstName;
        cellPhone::contacts[currentIndex].lastName = lastName;
        cellPhone::contacts[currentIndex].homeContacttNumber = homeContactNumber;
        cellPhone::contacts[currentIndex].mobileContactNumber = mobileContactNumber;
        cellPhone::contacts[currentIndex - 1].hasNext = true;
    }
    return true;
}
void cellPhone::dialContact(string firstName, string lastName)
{
    int currentIndex;
    for (currentIndex = 0; currentIndex < cellPhone::contactCount(contacts); currentIndex++)
    {
        if (cellPhone::contacts[currentIndex].firstName == firstName && cellPhone::contacts[currentIndex].lastName == lastName)
        {
            cout << "Call Home or Mobile number? (H/M)" << endl;
            char numberChoice;
            cin >> numberChoice;
            switch (numberChoice)
            {
                case 'h':
                case 'H':
                    cellPhone::currentCall = cellPhone::contacts[currentIndex].homeContactNumber;
                    cellPhone::display = cellPhone::contacts[currentIndex].homeContactNumber;
                    break;
                case 'm':
                case 'M':
                    cellPhone::currentCall = cellPhone::contacts[currentIndex].mobileContactNumber;
                    cellPhone::display = cellPhone::contacts[currentIndex].mobileContactNumber;
                    break;
                default:
                    break;
            }
            cellPhone::showOutput();
        }
    }
    if (currentIndex == cellPhone::contactCount(contacts) + 1)
    {
        cout << "No results found" << endl;
    }

}
void cellPhone::displayContactNumberInformation(string number)
{
    int currentIndex;
    for (currentIndex = 0; currentIndex < cellPhone::contactCount(contacts); currentIndex++)
    {
        if (cellPhone::contacts[currentIndex].homeContactNumber == number || cellPhone::contacts[currentIndex].mobileContactNumber == number) {
            cellPhone::display = "First Name: " + cellPhone::contacts[currentIndex].firstName + "\nLast Name: " + cellPhone::contacts[currentIndex].lastName;
        }
        cellPhone::showOutput();
    }
    if (currentIndex == cellPhone::contactCount(contacts) + 1)
    {
        cout << "Number does not exist" << endl;
    }

}
void cellPhone::powerDown()
{
    cellPhone::isOn = false;
    cellPhone::display = "This device has been powered off";
    cellPhone::showOutput();
}

bool cellPhone::getPowerState()
{
    return cellPhone::isOn;
}
