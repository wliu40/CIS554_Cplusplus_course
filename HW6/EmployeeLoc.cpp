// EmployeeLoc.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// Prompt the use to enter the name and location for an employee, then the program will 
// print out where that employee is located. 
//
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "Empolyee.h"
#include "Location.h"
#include "Point.h"
#include "Set.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
bool input(int &); // a helper function for input the correct integer
int main()
{
	string name; //store the name of employee from user input
	int xPos = 0; // store the x position from user input
	int yPos = 0; // store the y position from user input

	//instantiate the class instances
	Point point;
	Location location;	
	Employee somebody;

	while (1)
	{
		cout << "Enter Emplyee Name: ";
		getline(cin, name); // space between first and last name was allowed

		while (1)
		{
			cout << "Enter X position(-1 to quit): ";
			if (input(xPos)) // if input success, break; otherwise, continue cin;
				break;
		}
		if (xPos == -1) // if xPos is -1, terminate the outer loop
			break;

		while (1)
		{
			cout << "Enter Y position(-1 to quit): ";
			if (input(yPos)) // if input success, break; otherwise, continue cin;
				break;
		}
		if (yPos == -1) // if xPos is -1, terminate the outer loop
			break;

		cin.get(); // "eat" the remaining "\n" in the istream buffer

		// set the member values of object point and somebody 
		point.setX(xPos);
		point.setY(yPos);
		somebody.setCoordinates(point);
		somebody.setName(name);
		
		// print the information the user's input 
		cout << endl;
	//	if (location.isValid())
			cout << somebody.getName() << " is in " << location.getCity(point) << endl;
	//	else
	//		cout << somebody.getName() << "'s location not found" << endl;
		cout << endl;
	}

}

//return true if the input from cin is a valid integer, else return false 
bool input(int &val)
{
	// if the input is not an integer, (cin >> val) will return 'false',
	// !(cin >> val) return "true",anyway, the "val" will accept a stream from cin
	if (!(cin >> val)) 
	{
		cout << "\n[Error]: Please only input integer number!\n" << endl;
		cin.clear(); // clean the condition state of cin
		while (cin.get() != '\n'); //'rinse' the remaining chars in stream, exaust until '\n'
		return false;
	}
	if (val < -1 || val > 20) // check if the inputed number is in the valid range, if not, return false.
	{
		cout << "\n[ERROR]: The range is 0 to 20. Please check." << endl;
		return false;
	}		
	return true;
}

