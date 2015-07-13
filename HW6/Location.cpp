////////////////////////////////////////////////////////////////////////////////////////
// Location.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// cpp descriptinon: 
// This is the impletement of the the Class Location
//
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Location.h"
#include "Point.h"
using std::cout;
using std::endl;
using std::string;
// constructor that initialize all the sets for different cities
Location::Location() : locNY(Set(0, 5)), locSAN(Set(6, 10)), locLOS(Set(11, 15)), locCHI(Set(16, 20))
{
	flag = true;
}

Location::LOCATION Location::getLocation(Point &p)
{
	int x = p.getX();
	int y = p.getY();
	if (locNY.isMember(x) && locNY.isMember(y))
		return NEWYORK;
	else if (locSAN.isMember(x) && locSAN.isMember(y))
		return SANFRANSISCO;
	else if (locLOS.isMember(x) && locLOS.isMember(y))
		return LOSANGELES;
	else if (locCHI.isMember(x) && locCHI.isMember(y))
		return CHICAGO;
	else
		return NOT_FOUND;
}
string Location::getCity(Point &p)
{
	flag = true;
	switch ( getLocation(p) )
	{
	case Location::NOT_FOUND:
		flag = false;
		return "location not found";		
	case Location::NEWYORK:
		return "New York City";
	case Location::SANFRANSISCO:
		return "San Francisco";
	case Location::LOSANGELES:
		return "Los Angeles";
	case Location::CHICAGO:
		return "Chicago";
	default:
		cout << "[ERROR]program should not reach here!" << endl;
		return NULL;
	}
}
bool Location::isValid()
{
	return flag;
}