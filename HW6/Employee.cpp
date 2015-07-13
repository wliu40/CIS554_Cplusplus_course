////////////////////////////////////////////////////////////////////////////////////////
// Employee.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// cpp descriptinon: 
// The Employee will store names and coordinates(Point class) as private data members.
// The class will provide public get and set functions for user's input and inquiry.
////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Point.h"
#include "Empolyee.h"

using namespace std;


Employee::Employee()
{

}
Employee::Employee(const string &inputName, const Point &inputPoint)
{
	setName(inputName);
	setCoordinates(inputPoint);

}

void Employee::setCoordinates(const Point &inputPoint)
{
	coordinates = inputPoint;
}
Point Employee::getCoordinates()
{
	return coordinates;
}
void Employee::setName(const string &inputName)
{
	name = inputName;
    //name(inputName);
}
string Employee::getName()
{
	return name;
}
