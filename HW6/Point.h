////////////////////////////////////////////////////////////////////////////////////////
// Point.h
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

#ifndef POINT_H
#define POINT_H

class Point
{
public:
	// constructors
	Point();
	Point(int XVal, int YVal);

	// set and get functions
	void setX(int XVal);
	int getX();
	void setY(int YVal);
	int getY();
private:
	int x;
	int y;

};

#endif