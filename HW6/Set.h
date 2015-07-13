////////////////////////////////////////////////////////////////////////////////////////
// Set.h
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

#ifndef SET_H
#define SET_H
#include <vector>
using std::vector;
class Set
{
public:
	// constructors
	Set(); // set the value of size
	Set(vector<int> & v); // construct a set by pass a reference of a vector
	Set(const int & min, const int & max); // construct a set from min to max

	bool isMember(const size_t) const; // is a number member of the set
	Set & Union(const Set & v); // return itself after union with another Set
	Set & Intersection(const Set & v); // return itself after intersection with another Set
	void print() const; // print the Set
	size_t getSize() const; // get the size of the Set

private:
	vector<bool> boolVector; // use a bool vector to keep track the values in this Set
	const size_t size; // the default size of the Set is 21: from 0 to 20

};

#endif