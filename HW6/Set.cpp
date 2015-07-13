////////////////////////////////////////////////////////////////////////////////////////
// Set.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// Use a bool vector to track the numbers in a Set. The class provide public function
// which can Union and Intersection with another Set.
// The size of the Set is 21, the possible numbers are from 0 to 20, inclusive.
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include "Set.h"
using namespace std;

Set::Set():size(21)
{
	boolVector.resize(size);
	for (auto &b : boolVector)
		b = false;
}

Set::Set(vector<int> & v) : size(21)
{
	//adjust the boolVector accordingly
	boolVector.resize(size);
	for (auto &b : boolVector)
		b = false;

	for (size_t i = 0; i < v.size(); i++)
	{
		boolVector.at( v.at(i) ) = true;
	}
}
Set::Set(const int &min, const int &max) : size(21) // constructor overload
{
	boolVector.resize(size);
	for (auto &b : boolVector)
		b = false;
	for (int i = min; i <= max; i++)
	{
		boolVector.at(i) = true;
	}
}
size_t Set::getSize() const
{
	return size;
}

bool Set::isMember(size_t val) const
{
	return boolVector.at(val);
}
Set & Set::Union(const Set & s)
{
	for (size_t i = 0; i < s.getSize(); i++) // travese the vector of s, if an element is true, set vec as true
	{
		if (s.isMember(i) && !this->isMember(i))
		{
			boolVector.at(i) = true;
		}
	}
	return *this;
}
Set & Set::Intersection(const Set & s)
{

	for (size_t i = 0; i < s.getSize(); i++) // travese the vector of s, if an element is true, set vec as true
	{

		if (s.isMember(i) && this->isMember(i))
		{
			boolVector.at(i) = true;
		}
		else
			boolVector.at(i) = false;

	}
	return *this;
}

void Set::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		if (isMember(i))
			cout << i << " ";
	}
	cout << endl;
}
