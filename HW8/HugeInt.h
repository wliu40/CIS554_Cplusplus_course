////////////////////////////////////////////////////////////////////////////////////////
// HugeInt.h
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 8
// Author: Wei Liu
// Date: 4/26/2015
// -----------------------------------------------------------------------------------
// Class HugeInt header file
//
// Description - This is the header file for class HugeInt.
// This class enables us to manipulate large integer numbers, which is longer than the 
// int data type. It can maximumly handle 30 digits integers.
// Operators such as +, -, *, /, ==, !=, <, >, <=, >= were overloaded.
////////////////////////////////////////////////////////////////////////////////////////



// Exercise 11.9 Solution: Hugeint.h
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
	//overloading the operator <<
	friend ostream &operator<<(ostream &, const HugeInt &);

	//overloading the operator ==, argument as shown
	friend bool operator==(const HugeInt&, const HugeInt &);
	friend bool operator==(const HugeInt&, long);
	friend bool operator==(long, const HugeInt &);
	friend bool operator==(const string&, const HugeInt&);
	friend bool operator==(const HugeInt&, const string&);

	//overloading the operator !=, argument as shown
	friend bool operator!=(const HugeInt&, const HugeInt &);
	friend bool operator!=(const HugeInt&, long);
	friend bool operator!=(long, const HugeInt &);
	friend bool operator!=(const string&, const HugeInt&);
	friend bool operator!=(const HugeInt&, const string&);

	//overloading the operator <, argument as shown
	friend bool operator<(const HugeInt&, const HugeInt &);
	friend bool operator<(const HugeInt&, long);
	friend bool operator<(long, const HugeInt&);
	friend bool operator<(const string&, const HugeInt&);
	friend bool operator<(const HugeInt&, const string&);

	//overloading the operator >, argument as shown
	friend bool operator>(const HugeInt&, const HugeInt &);
	friend bool operator>(const HugeInt&, long);
	friend bool operator>(long, const HugeInt&);
	friend bool operator>(const string&, const HugeInt&);
	friend bool operator>(const HugeInt&, const string&);

	//overloading the operator <=, argument as shown
	friend bool operator<=(const HugeInt&, const HugeInt &);
	friend bool operator<=(const HugeInt&, long);
	friend bool operator<=(long, const HugeInt&);
	friend bool operator<=(const string&, const HugeInt&);
	friend bool operator<=(const HugeInt&, const string&);

	//overloading the operator >=, argument as shown
	friend bool operator>=(const HugeInt&, const HugeInt &);
	friend bool operator>=(const HugeInt&, long);
	friend bool operator>=(long, const HugeInt&);
	friend bool operator>=(const string&, const HugeInt&);
	friend bool operator>=(const HugeInt&, const string&);

	//addition operator, argument as shown;
	friend HugeInt operator+(long, const HugeInt&);
	friend HugeInt operator+(const string&, const HugeInt&);

	//minus operator, argument as shown;
	friend HugeInt operator-(long, const HugeInt&);
	friend HugeInt operator-(const string&, const HugeInt&);

	//mutiply operator, argument as shown;
	friend HugeInt operator*(long, const HugeInt&);
	friend HugeInt operator*(const string&, const HugeInt&);

	//division operator, argument as shown;
	friend HugeInt operator/(long, const HugeInt&);
	friend HugeInt operator/(const string&, const HugeInt&);

public:
	static const int digits = 30; // maximum digits in a HugeInt

	HugeInt(long = 0); // conversion/default constructor
	HugeInt(const string &); // conversion constructor
	
	HugeInt operator+(const HugeInt &) const;// addition operator; HugeInt + HugeInt	
	HugeInt operator+(long) const;// addition operator; HugeInt + long
	HugeInt operator+(const string &) const;// addition operator; string represents a HugeInt obj

	//minus operator; similar as the addition operator above
	HugeInt operator-(const HugeInt&)const;
	HugeInt operator-(const string &)const;
	HugeInt operator-(long)const;

	//mutiply operator; similar as the addition operator above
	HugeInt operator*(const HugeInt&)const;
	HugeInt operator*(const string&)const;
	HugeInt operator*(long)const;

	//divide operator; similar as the addition operator above
	HugeInt operator/(const HugeInt&)const;
	HugeInt operator/(const string&)const;
	HugeInt operator/(long)const;

private:
	short integer[digits];//a array to store data for HugeInt
	bool isNegative;//return true if the HugeInt is negative
	bool multiplyErrorFlag; //helper boolean to determine if a overflow happens in mutiplication

	//helper private functions
	HugeInt absolutAdd(const HugeInt&) const; // add the absolute value with another object
	HugeInt absolutMinus(const HugeInt&) const;// get the absolute value with another object;
	bool absolutCompare(const HugeInt&)const; // compare the absolute value with another object
	HugeInt mutiplySingleDigits(int) const; // helper function, return *(this) multiply a single digit
	void multiplyTen();//shift the integer array to left for one position (the effect is equal to *10)
	HugeInt constructFun(int length)const;//return a new HugeInt object from *(this), copy the first lengths data to the new one
	int findPositionOfFirstNum() const;//find the index of the first none-zero element in *(this) integer array
	bool absolutEqual(const HugeInt& op2) const;//return a boolean, verify if two HugeInt has the same absolute value

}; // end class HugeInt

#endif


/**************************************************************************
* (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
* Pearson Education, Inc. All Rights Reserved.                           *
*                                                                        *
* DISCLAIMER: The authors and publisher of this book have used their     *
* best efforts in preparing the book. These efforts include the          *
* development, research, and testing of the theories and programs        *
* to determine their effectiveness. The authors and publisher make       *
* no warranty of any kind, expressed or implied, with regard to these    *
* programs or to the documentation contained in these books. The authors *
* and publisher shall not be liable in any event for incidental or       *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these programs.                     *
**************************************************************************/