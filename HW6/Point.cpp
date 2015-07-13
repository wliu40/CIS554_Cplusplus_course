////////////////////////////////////////////////////////////////////////////////////////
// Point.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// Class Point will store the coordinates x and y as private int variables. And the class
// will provide set and get function for users to input or inquiry the variables.
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Point.h"
using namespace std;

Point::Point()
{
	setX(0);
	setY(0);
}
Point::Point(int XVal, int YVal)
{
	setX(XVal);
	setY(YVal);
}
void Point::setX(int XVal)
{
	x = XVal;
}
void Point::setY(int YVal)
{
	y = YVal;
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
