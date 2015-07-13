////////////////////////////////////////////////////////////////////////////////////////
// HugeInt.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 8
// Author: Wei Liu
// Date: 4/26/2015
// -----------------------------------------------------------------------------------
// Class HugeInt Implementation part
//
// Description - This is the implement file for class HugeInt.
// This class enables us to manipulate large integer numbers, which is longer than the 
// int data type. It can maximumly handle 30 digits integers.
// Operators such as +, -, *, /, ==, !=, <, >, <=, >= were overloaded.
////////////////////////////////////////////////////////////////////////////////////////


// Exercise 11.9 Solution: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
#include <iostream>
#include <stdexcept>
#include <cctype> // isdigit function prototype
#include <vector>
#include "Hugeint.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt(long value)
{
	// initialize array to zero
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;
	long temp;
	isNegative = false;//by default, it is positive
	multiplyErrorFlag = false;
	if (value >= 0)
	{
		temp = value;
	}
	else
	{
		temp = -value;
		isNegative = true;
	}
	// place digits of argument into array
	for (int j = digits - 1; temp != 0 && j >= 0; --j)
	{
		integer[j] = temp % 10;
		temp /= 10;
	} // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt(const string &number)
{	
	//check wheather the input is a valid one
	bool valid = true;
	for (size_t i = 0; i < number.size(); i++)
	{
		if (number[0] == '-')//the first character is '-' is acceptable
			continue;
		if (!isdigit(number[i]))
		{
			valid = false;
			break;
		}
	}
	try
	{
		if (!valid)
			throw 1;
	}
	catch (int e)
	{
		cout << "[Error] Invalid input!! Error Code: " << e << endl;
		exit(e);
	}
	// initialize array to zero
	for (int i = 0; i < digits; ++i)
		integer[i] = 0;

	int length = number.size(); // length is the how many digits of argument number

	isNegative = false;//the isNegative flag is false by default
	multiplyErrorFlag = false;//initialize the mutiplyErrorFlag to false

	if (number[0] == '-')// if the input is a negative number
	{
		length = number.size() - 1;
		isNegative = true;
	}
	//if the input string is longer than 30 digits
	try
	{
		if (length > digits)
			throw 2;
	}
	catch (int e)
	{
		cout << "[Error] The input string is longer than 30 digits!! Error Code: " << e << endl;
		exit(e);
	}
	//initialize from the index of digits - length
	int k;
	if (isNegative)
		k = 1;
	else
		k = 0;
	for (int j = digits - length; j < digits; ++j, ++k)
		integer[j] = number[k] - '0';

} // end HugeInt conversion constructor
//helper function, add the absolute value of *this and op2
HugeInt HugeInt::absolutAdd(const HugeInt&op2) const
{
	HugeInt temp; // temporary result
	int carry = 0;

	for (int i = digits - 1; i >= 0; --i)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;
		// determine whether to carry a 1
		try
		{
			if (i == 0 && temp.integer[i] > 9)
			{				
				throw 3;
			}
		}
		catch (int e)
		{
			cout << "[Error]The addition is out of max range of HugeInt!! Error Code: " << e << endl;
			return NULL;
		}

		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;  // reduce to 0-9
			carry = 1;
		} // end if
		else // no carry
			carry = 0;
	} // end for

	return temp; // return copy of temporary object
}
//helper function, get the differec of absolute value of *this and op2
HugeInt HugeInt::absolutMinus(const HugeInt &op2) const
{
	//find the bigger one between *(this) and op2
	HugeInt big;
	HugeInt small;
	//compare the *(this) and op2, then assign them to big and small
	if (absolutCompare(op2))
	{
		big = op2;
		small = *(this);
	}
	else if (!absolutCompare(op2))
	{
		big = *(this);
		small = op2;
	}

	HugeInt temp;//stroe the final result
	int carry = 0;//initiate carry
	for (int i = digits - 1; i >= 0; --i)//start of for loop
	{
		//if on the index i, big.integer is smaller
		if (big.integer[i] < small.integer[i])
		{
			temp.integer[i] = 10 + big.integer[i] - carry - small.integer[i];
			carry = 1;
		}
		//if the index i has the same value
		else if (big.integer[i] == small.integer[i])
		{
			if (carry == 0)
				temp.integer[i] = 0;
			else if (carry == 1)
			{
				temp.integer[i] = 9;
				carry = 1;
			}
		}
		else//the big.integer[i] is bigger
		{
			temp.integer[i] = big.integer[i] - carry - small.integer[i];
			carry = 0;
		}
	} // end for
	return temp;
}
// helper function, return *(this) multiply a single digit
HugeInt HugeInt::mutiplySingleDigits(int num) const 
{
	if (num == 0 || *(this) == 0)
		return 0;

	HugeInt temp;//stroe final data to return
	int carry = 0;
	int result;
	for (int i = digits - 1; i >= 0; i--)
	{
		result = integer[i] * num + carry;
		carry =  result / 10;
		temp.integer[i] = result % 10;
	}
	return temp;
}
//helper function, shift the integer array to left for one position (equal to *10)
void HugeInt::multiplyTen()
{
	int i;
	for (i = 0; i < digits - 1; i++)
	{
		if (i == 0 && integer[i] != 0)
		{
			multiplyErrorFlag = true;
			return;
		}
		integer[i] = integer[i + 1];
	}
	integer[i] = 0;
}
//*************************************************************************************
//overload operator*
HugeInt HugeInt::operator*(const HugeInt&op2)const
{
	int position = 29;//default position of operation, put it as the last digis default

	for (int i = 0; i < digits; i++)
	{
		if (op2.integer[i] == 0)
			continue;
		else
		{
			position = i;
			break;
		}
	}
	HugeInt temp;//store the final result

	for (int i = position; i < digits; i++)
	{
		//if the product of two factors exceeds the max limit of the HugeInt range.
		try
		{
			if (temp.multiplyErrorFlag)			
				throw 4;
		}
		catch (int e)
		{
			cout << "[Error] Multiple Out of the max range of HugeInt!! Error Code: " << e << " " << endl;
			return NULL;
		}
		//otherwise
		temp = temp + mutiplySingleDigits(op2.integer[i]);
		if (i != digits -1)
			temp.multiplyTen();
	}
	if (isNegative != op2.isNegative)
		temp.isNegative = true;
	return temp;
}
//overload operator*, argument is a string
HugeInt HugeInt::operator*(const string&num)const
{
	return *(this)*HugeInt(num);
}
//overload operator*, argument is a long number
HugeInt HugeInt::operator*(long num)const
{
	return *(this)*HugeInt(num);
}
//overload operator*, first argument is a long, second is a HugeInt obj
HugeInt operator*(long num, const HugeInt&op2)
{
	return (HugeInt(num) * op2);
}
//overload operator*, first argument is a string, second is a HugeInt obj
HugeInt operator*(const string&num, const HugeInt&op2)
{
	return (HugeInt(num) * op2);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// this helper function can construct a new HugeInt object from the first length digits
//e.g., if HugeInt x("1234567890123"), then constructFun(6) will return HugeInt("123456");
HugeInt HugeInt::constructFun(int length) const
{
	HugeInt temp;
	try
	{
		if (length > digits - findPositionOfFirstNum())
		{
			throw 5;			
		}
	}
	catch (int e)
	{
		cout << "[Error]Can not construct when length is longer than its own length!! Error Code: " << e << endl;
		return NULL;
	}
	
	for (int i = 0 ; i < length; i++)
	{
		temp.integer[digits - length + i] = integer[findPositionOfFirstNum() + i];
	}
	return temp;
}
//return the index of the first none-zero element in the integer array
//e.g., the HugeInt object of 12345 will return 25, because the index of 1 is 25
int HugeInt::findPositionOfFirstNum() const
{
	int position = 29;
	for (int i = 0; i < digits; i++)
	{
		if (integer[i] == 0)
			continue;
		else
		{
			position = i;
			break;
		}
	}
	return position;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//overload operator /
HugeInt HugeInt::operator/(const HugeInt&op2)const
{
	HugeInt result;//to store the final result
	vector<int> vec;//helper vector to store data of caculation

	//if the numerator's abolute value is less than the denominator, return 0
	if (absolutCompare(op2))
		return 0;

	//if the denominator is zero, then an error msg was printed, and return NULL
	try
	{
		if (op2 == 0)
		{
			throw 6;			
		}
	}
	catch (int e)
	{
		cout << "[Error] The denominator can't be 0!! Error Code: " << e << ", program's terminated" << endl;
		exit(6);
	}
	//if the denominator is 1 or -1, return *(this), and change its isNegative flag
	if (op2 == 1 || op2 == -1)
	{
		result = *(this);
		if (isNegative != op2.isNegative)
			result.isNegative = true;
		return result;
	}
	//if their absolute value is equal
	if (absolutEqual(op2))
	{
		if (isNegative != op2.isNegative)
			return -1;
		return 1;
	}

	//all other cases
	int length_op2 = digits - op2.findPositionOfFirstNum();
	HugeInt temp;//to store the temporal data in this process
	int positionOfFirstQuotientNum = findPositionOfFirstNum() + length_op2;

	//construct the temp
	//e.g., if the divisor is 123456, the dividend is 123456789, then the temp will be 123456
	temp = constructFun(length_op2);	

	//cout << "findPosition is: " << findPosition() << endl;
	//cout << "length_op2 is: " << length_op2 << endl;

	//e.g.,if the divisor is 123, the dividend is 12101, then the temp will be 1210
	if (temp.absolutCompare(op2))
	{		
		temp = constructFun(length_op2 + 1);
		positionOfFirstQuotientNum += 1;
	}

	int i;//loop cnt
	HugeInt tempProduct;//stroe the helper temporal data in the process
	for (int j = positionOfFirstQuotientNum; j <= digits; j++)
	{
		for (i = 1; i <= 10; i++)
		{
			tempProduct = op2*i;
			if (tempProduct.absolutEqual(temp))//if the product's absolute value equals to temp
			{	
				vec.push_back(i);//i is the quotient in this round
				if (j < digits)
				{
					temp = integer[j];
				}
				break;
			}
			else if (!tempProduct.absolutCompare(temp)) //if product's absolute value is greater than temp
			{
				vec.push_back(i-1);//i is the quotient in this round
				if (j < digits)
					temp = (temp.absolutMinus(op2*(i-1))) * 10 + integer[j];
				break;
			}		
		}
	}//end of for loop

	//input value to result, from the vector
	for (size_t i = 0; i < vec.size(); i++)
	{
		result.integer[digits - vec.size() + i] = vec[i];		
	}

	//revise the isNegative flag of the result if necessray
	if (isNegative != op2.isNegative)
		result.isNegative = true;
	return result;//return a HugeInt obj
}
//overload operator /
HugeInt HugeInt::operator/(const string &num)const
{
	return (*(this) / HugeInt(num));
}
//overload operator /
HugeInt HugeInt::operator/(long num)const
{
	return ((*this) / HugeInt(num) );
}
//overload operator /
HugeInt operator/(long num, const HugeInt&op2)
{
	return (HugeInt(num) / op2);
}
//overload operator /
HugeInt operator/(const string&num, const HugeInt&op2)
{
	return (HugeInt(num) / op2);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &op2) const
{
	HugeInt temp;

	if (isNegative)//if *(this) is a negative number
	{
		if (!op2.isNegative) // if op2 is a positive number or zero
		{
			temp = absolutMinus(op2);
			if (!absolutCompare(op2))
				temp.isNegative = true;
		}
		else //if op2 is a negative number
		{
			temp = absolutAdd(op2);
				temp.isNegative = true;
		}
	}
	else //if *(this) is a positive number
	{
		if (!op2.isNegative)//if op2 is positive or zero
		{
			temp = absolutAdd(op2);
		}
		else//if op2 is negative
		{
			temp = absolutMinus(op2);
			if (absolutCompare(op2))// if |*(this)| < |op2|
			{
				temp.isNegative = true;
			}
		}
	}
	if (temp == 0)
		temp.isNegative = false;
	return temp;

} // end function operator+

// addition operator; HugeInt + int
HugeInt HugeInt::operator+(long op2) const
{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
	return *this + HugeInt(op2);
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+(const string &op2) const
{
	// convert op2 to a HugeInt, then invoke operator+ for two HugeInt objects
	return *this + HugeInt(op2);
} // end function operator+
//overload operator +
HugeInt operator+(long num, const HugeInt&op2)
{
	return (op2 + HugeInt(num));
}
//overload operator +
HugeInt operator+(const string&num, const HugeInt&op2)
{
	return (HugeInt(num)+op2);
}
//------------------------------------------------------------------------------------------
//overload operator -
HugeInt HugeInt::operator-(const HugeInt&op2) const
{
	HugeInt temp;
	if (*(this) == op2)
	{
		return 0;
	}
	else
	{
		if (isNegative)//if *(this) is a negative number
		{
			if (!op2.isNegative) // if op2 is a positive number
			{
				temp = absolutAdd(op2);
				temp.isNegative = true;
			}
			else //if op2 is a negative number
			{
				temp = absolutMinus(op2);
				if (!absolutCompare(op2)) // if *(this) is greater or equal to op2
				{
					temp.isNegative = true;
				}
			}
		}
		else //if *(this) is a positive number or zero
		{
			if (op2.isNegative)//if op2 is a negative number
			{
				temp = absolutAdd(op2);
			}
			else //if op2 is a positive number
			{
				temp = absolutMinus(op2);
				if (absolutCompare(op2))
				{
					temp.isNegative = true;
				}
			}
		}
	}
	if (temp == 0)
		temp.isNegative = false;
	return temp;
}
//overload operator -
HugeInt HugeInt::operator-(const string &num)const
{
	return (*(this) - HugeInt(num));
}
//overload operator -
HugeInt HugeInt::operator-(long num)const
{
	return (*(this) - HugeInt(num));
}
//overload operator -
HugeInt operator-(long num, const HugeInt&op2)
{
	return (HugeInt(num) - op2);
}
//overload operator -
HugeInt operator-(const string&num, const HugeInt&op2)
{
	return (HugeInt(num) - op2);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
// overloaded output operator
ostream& operator<<(ostream &output, const HugeInt &num)
{
	int i;

	for (i = 0; i < HugeInt::digits && num.integer[i] == 0; ++i)
		; // skip leading zeros

	if (i == HugeInt::digits)
		output << 0;
	else
	{
		if (num.isNegative)
			output << '-';

		for (; i < HugeInt::digits; ++i)
		{
			output << num.integer[i];
		}
	}
	return output;
} // end function operator<<

/////////////////////////////////////////////////////////////////////////////////////////////////
////compare the absolute value of *(this) and thatObj, return true if smaller, otherwise return false
bool HugeInt::absolutCompare(const HugeInt&thatObj)const
{
	int i, j;

	for (i = 0; i < HugeInt::digits && integer[i] == 0; ++i)
		; // skip leading zeros

	for (j = 0; j < HugeInt::digits && thatObj.integer[j] == 0; ++j)
		; // skip leading zeros

	if (i < j)
		return false; // if thisObj has more digits than thatObj, return false
	if (i > j) // if thisObj has less digits than thatObj, return true
		return true;
	else// if thisObj has the same length of digits with thatObj
	{		
		for (int k = i; k < HugeInt::digits; ++k)
		{
			if (integer[k] > thatObj.integer[k])
				return false;
				
			else if (integer[k] < thatObj.integer[k])
				return true;
		}
		return false; //thisObj == thisObj
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//compare the absolute value of *(this) and op2, return true if equal, otherwise return false
bool HugeInt::absolutEqual(const HugeInt& op2) const
{
	for (int i = digits - 1; i >= 0; i--)
	{
		if (integer[i] != op2.integer[i])
			return false;
	}
	return true;
}
//overload the operator ==
bool operator==(const HugeInt&thisObj, const HugeInt &thatObj)
{
	if (thisObj.isNegative != thatObj.isNegative)
		return false;

	return thisObj.absolutEqual(thatObj);
}
//overload the operator ==
bool operator==(const HugeInt&thisObj, long num)
{
	return (thisObj == HugeInt(num));
}
//overload the operator ==
bool operator==(long num, const HugeInt&thisObj)
{
	return (HugeInt(num) == thisObj);
}
//overload the operator ==
bool operator==(const string& num, const HugeInt&thisObj)
{
	return (HugeInt(num) == thisObj);
}
//overload the operator ==
bool operator==(const HugeInt&thisObj, const string& num)
{
	return (thisObj == HugeInt(num));
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//overload the operator !=
bool operator!=(const HugeInt&thisObj, const HugeInt &thatObj)
{
	return !(thisObj == thatObj);
}
//overload the operator !=
bool operator!=(const HugeInt&thisObj, long num)
{
	return !(thisObj == HugeInt(num));
}
//overload the operator !=
bool operator!=(long num, const HugeInt&thisObj)
{
	return !(HugeInt(num) == thisObj);
}
//overload the operator ==
bool operator!=(const string& num, const HugeInt&thisObj)
{
	return (HugeInt(num) != thisObj);
}
//overload the operator ==
bool operator!=(const HugeInt&thisObj, const string& num)
{
	return (thisObj != HugeInt(num));
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//overload the operator <
bool operator<(const HugeInt&thisObj, const HugeInt &thatObj)
{
	if (thisObj.isNegative == false && thatObj.isNegative == false)
		return thisObj.absolutCompare(thatObj);
	else if (thisObj.isNegative == true && thatObj.isNegative == true)
	{
		if (thisObj == thatObj)
			return false;
		else
			return !thisObj.absolutCompare(thatObj);
	}
	else if (thisObj.isNegative == false && thatObj.isNegative == true)
		return false;
	else if (thisObj.isNegative == true && thatObj.isNegative == false)
		return true;
	return false;
}
//overload the operator <
bool operator<(const HugeInt&thisObj, long num)
{
	return (thisObj < HugeInt(num));
}
//overload the operator <
bool operator<(long num, const HugeInt&thisObj)
{
	return (HugeInt(num) < thisObj);
}
//overload the operator <
bool operator<(const string& num, const HugeInt&thisObj)
{
	return (HugeInt(num) < thisObj);
}
//overload the operator <
bool operator<(const HugeInt&thisObj, const string& num)
{
	return (thisObj < HugeInt(num));
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//overload the operator >
bool operator>(const HugeInt&thisObj, long num)
{
	return (thisObj > HugeInt(num));
}
//overload the operator >
bool operator>(long num, const HugeInt&thisObj)
{
	return (HugeInt(num) > thisObj);
}
//overload the operator >
bool operator>(const HugeInt&thisObj, const HugeInt &thatObj)
{
	if (thisObj < thatObj || thisObj == thatObj)
		return false;
	return true;
}
//overload the operator >
bool operator>(const string& num, const HugeInt&thisObj)
{
	return (HugeInt(num) > thisObj);
}
//overload the operator >
bool operator>(const HugeInt&thisObj, const string& num)
{
	return (thisObj > HugeInt(num));
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//overload the operator <=
bool operator<=(const HugeInt&thisObj, const HugeInt &thatObj)
{
	return !(thisObj > thatObj);
}
//overload the operator <=
bool operator<=(const HugeInt&thisObj, long num)
{
	return (thisObj <= HugeInt(num));
}
//overload the operator <=
bool operator<=(long num, const HugeInt&thisObj)
{
	return (HugeInt(num) <= thisObj);
}
//overload the operator <=
bool operator<=(const string& num, const HugeInt&thisObj)
{
	return (HugeInt(num) <= thisObj);
}
//overload the operator <=
bool operator<=(const HugeInt&thisObj, const string& num)
{
	return (thisObj <= HugeInt(num));
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//overload the operator >=
bool operator>=(const HugeInt&thisObj, const HugeInt &thatObj)
{
	return !(thisObj < thatObj);
}
//overload the operator >=
bool operator>=(const HugeInt&thisObj, long num)
{
	return (thisObj >= HugeInt(num));
}
//overload the operator >=
bool operator>=(long num, const HugeInt&thisObj)
{
	return (HugeInt(num) >= thisObj);
}
//overload the operator >=
bool operator>=(const string& num, const HugeInt&thisObj)
{
	return (HugeInt(num) >= thisObj);
}
//overload the operator >=
bool operator>=(const HugeInt&thisObj, const string& num)
{
	return (thisObj >= HugeInt(num));
}
///////////////////////////////////////////////////////////////////////////
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