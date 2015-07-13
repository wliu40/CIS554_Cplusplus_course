////////////////////////////////////////////////////////////////////////////////////////
// Employee.h
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// The Employee will store names and coordinates(Point class) as private data members.
// The class will provide public get and set functions for user's input and inquiry.
////////////////////////////////////////////////////////////////////////////////////////
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include "Point.h"
using std::cout;
using std::endl;
using std::string;

class Employee
{
public:
	Employee();
	Employee(const string &, const Point &);
	void setCoordinates(const Point &);
	Point getCoordinates();
	void setName(const string &);
	string getName();
private:
	Point coordinates;
	string name;
};



#endif