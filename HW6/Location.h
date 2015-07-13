////////////////////////////////////////////////////////////////////////////////////////
// Location.h
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// This class will store the coordinates of several large US cities.
// The cities includes: New York City, San Francisco, Los Angeles, Chicago
////////////////////////////////////////////////////////////////////////////////////////
#ifndef LOCATION_H
#define LOCATION_H

#include "Set.h"
#include "Point.h"
#include <string>
using std::string;
class Location
{
	enum LOCATION{ NOT_FOUND, NEWYORK, SANFRANSISCO, LOSANGELES, CHICAGO };
public:
	Location(); // default constructor
	LOCATION getLocation(Point &p); // constructor that initialize all the sets for different cities
	
	string getCity(Point &p);
	
	bool isValid(); // tell if the location is a valid city

private:
	bool flag; // flag == true, it is a valid city, otherwise, not a city
	const Set locNY;
	const Set locSAN;
	const Set locLOS;
	const Set locCHI;
};

#endif