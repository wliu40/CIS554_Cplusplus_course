////////////////////////////////////////////////////////////////////////////////////////
// HugeIntTest.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 8
// Author: Wei Liu
// Date: 4/26/2015
// -----------------------------------------------------------------------------------
// Class HugeInt Implementation of Test driver
//
// Description - This file is a test driver of HugeInt class
// HugeInt class enables us to manipulate large integer numbers, which is longer than the 
// int data type. It can maximumly handle 30 digits integers.
// Operators such as +, -, *, /, ==, !=, <, >, <=, >= were overloaded.
////////////////////////////////////////////////////////////////////////////////////////


// HugeInt test program.
#include <iostream>
#include <iomanip>
#include "Hugeint.h"
using namespace std;

int main()
{
	HugeInt n0(-7654321);
	HugeInt n1(7891234);
	HugeInt n2("99999999999999999999999999999");
	HugeInt n3("-99999999999999999999999999999");
	HugeInt n4("0");

	HugeInt n5("1234567898765432188776655443");
	HugeInt n6("88888888888888888888888888888");
	HugeInt n7("88888888888888888888888888888");
	HugeInt n8("123456");
	HugeInt n9("1");
	HugeInt n10("0");
	HugeInt n10_1(0);
	HugeInt n11("-1");
	HugeInt n12("-10000000000000000000000000001");
	HugeInt n13("-10000000000000000000000000001");
	HugeInt n14("-123456");
	HugeInt n15("999999999999999999999999999999");//n15 is the max positive number
    HugeInt n16("-123456789012345678901234567890");//n16 has the max length as a negative number
	HugeInt result;

	cout << "****************   1.Testing constructors and the operator <<   ****************" << endl << endl;
	//print the listed objects
	cout << "n0 = " << n0 << endl;
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n10_1 = " << n10_1 << endl;
	cout << "n15 = " << n15 << endl;
	cout << "n16 = " << n16 << endl;
	cout << "result = " << result << " (default is 0)" << endl << endl;

	cout << "************   2.Testing equality == and inequality != operators   ************" << endl << endl;
	//print the listed objects for reference
	cout << "n5 = " << n5 << endl;
	cout << "n6 = " << n6 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "n8 = " << n8 << endl;
	cout << "n9 = " << n9 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n11 = " << n11 << endl;
	cout << "n12 = " << n12 << endl;
	cout << "n13 = " << n13 << endl;
	cout << "n14 = " << n14 << endl << endl;

	cout << setw(14) << left << "n5 == n6 ?" << boolalpha << setw(8) << (n5 == n6) << endl;
	cout << setw(14) << left << "n5 == n7 ?" << boolalpha << setw(8) << (n5 == n7) << endl;
	cout << setw(14) << left << "n5 == n10 ?" << boolalpha << setw(8) << (n5 == n10) << endl;
	cout << setw(14) << left << "n5 == n11 ?" << boolalpha << setw(8) << (n5 == n11) << endl;
	cout << setw(14) << left << "n5 == n12 ?" << boolalpha << setw(8) << (n5 == n12) << endl << endl;

	cout << setw(14) << left << "n7 == n5 ?" << boolalpha << setw(8) << (n7 == n5) << endl;
	cout << setw(14) << left << "n7 == n6 ?" << boolalpha << setw(8) << (n7 == n6) << endl;
	cout << setw(14) << left << "n7 == n7 ?" << boolalpha << setw(8) << (n7 == n7) << endl;
	cout << setw(14) << left << "n7 == n8 ?" << boolalpha << setw(8) << (n7 == n8) << endl;
	cout << setw(14) << left << "n7 == n10 ?" << boolalpha << setw(8) << (n7 == n10) << endl;
	cout << setw(14) << left << "n7 == n12 ?" << boolalpha << setw(8) << (n7 == n12) << endl << endl;

	cout << setw(20) << left << "n8 == 123456 ?" << boolalpha << setw(8) << (n8 == 123456) << endl;
	cout << setw(20) << left << "123456 == n8 ?" << boolalpha << setw(8) << (123456 == n8) << endl;
	cout << setw(20) << left << "n14 == \"-123456\" ?" << boolalpha << setw(8) << (n14 == "-123456") << endl;
	cout << setw(20) << left << "\"-123456\" == n8 ?" << boolalpha << setw(8) << ("-123456" == n14) << endl << endl;

	cout << setw(14) << left << "n7 == 0 ?" << boolalpha << setw(8) << (n7 == 0) << endl;
	cout << setw(14) << left << "n10 == 0 ?" << boolalpha << setw(8) << (n10 == 0) << endl;
	cout << setw(14) << left << "n14 == 0 ?" << boolalpha << setw(8) << (n14 == 0) << endl << endl;

	cout << setw(14) << left << "n12 != n6 ?" << boolalpha << setw(8) << (n12 != n6) << endl;
	cout << setw(14) << left << "n12 != n7 ?" << boolalpha << setw(8) << (n12 != n7) << endl;
	cout << setw(14) << left << "n12 != n10 ?" << boolalpha << setw(8) << (n12 != n10) << endl;
	cout << setw(14) << left << "n12 != n13 ?" << boolalpha << setw(8) << (n12 != n13) << endl << endl;

	cout << setw(20) << left << "123456 != n8 ?" << boolalpha << setw(15) << (123456 != n8) << endl;
	cout << setw(20) << left << "n14 != -123457 ?" << boolalpha << setw(15) << (n14 != -123457) << endl << endl;
	cout << setw(20) << left << "\"123456\" != n8 ?" << boolalpha << setw(15) << ("123456" != n8) << endl;
	cout << setw(20) << left << "n14 != -123457 ?" << boolalpha << setw(15) << (n14 != "-123457") << endl << endl;

	cout << setw(14) << left << "n10 != 0 ?" << boolalpha << setw(8) << (n10 != 0) << endl;
	cout << setw(14) << left << "n10 != n5 ?" << boolalpha << setw(8) << (n10 != n5) << endl;
	cout << setw(14) << left << "n10 != n7 ?" << boolalpha << setw(8) << (n10 != n7) << endl;
	cout << setw(14) << left << "n10!= n12 ?" << boolalpha << setw(8) << (n10 != n12) << endl;
	cout << setw(14) << left << "n10 != n10 ?" << boolalpha << setw(8) << (n10 != n10) << endl << endl;

	cout << "*************************   3.Testing  operators < and > **********************" << endl << endl;

	cout << "n5 = " << n5 << endl;
	cout << "n6 = " << n6 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "n8 = " << n8 << endl;
	cout << "n9 = " << n9 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n11 = " << n11 << endl;
	cout << "n12 = " << n12 << endl;
	cout << "n13 = " << n13 << endl;
	cout << "n14 = " << n14 << endl << endl;

	cout << setw(14) << left << "n5 < n6 ?" << boolalpha << setw(8) << (n5 < n6) << endl;
	cout << setw(14) << left << "n5 < n7 ?" << boolalpha << setw(8) << (n5 < n7) << endl;
	cout << setw(14) << left << "n5 < n9 ?" << boolalpha << setw(8) << (n5 < n9) << endl;
	cout << setw(14) << left << "n5 < n10 ?" << boolalpha << setw(8) << (n5 < n10) << endl;
	cout << setw(14) << left << "n5 < n11 ?" << boolalpha << setw(8) << (n5 < n11) << endl;
	cout << setw(14) << left << "n5 < n12 ?" << boolalpha << setw(8) << (n5 < n12) << endl;
	cout << setw(20) << left << "n5 < 12569874 ?" << boolalpha << setw(8) << (n5 < 12569874) << endl;
	cout << setw(20) << left << "12569874 < n5 ?" << boolalpha << setw(8) << (12569874 < n5) << endl ;
	cout << setw(20) << left << "n5 < \"12569874\" ?" << boolalpha << setw(8) << (n5 < "12569874") << endl;
	cout << setw(20) << left << "\"12569874\" < n5 ?" << boolalpha << setw(8) << ("12569874" < n5) << endl << endl;

	cout << setw(14) << left << "n5 > n6 ?" << boolalpha << setw(8) << (n5 > n6) << endl;
	cout << setw(14) << left << "n5 > n9 ?" << boolalpha << setw(8) << (n5 > n9) << endl;
	cout << setw(14) << left << "n5 > n10 ?" << boolalpha << setw(8) << (n5 > n10) << endl;
	cout << setw(14) << left << "n5 > n11 ?" << boolalpha << setw(8) << (n5 > n11) << endl;
	cout << setw(20) << left << "n5 > \"12569874\" ?" << boolalpha << setw(8) << (n5 > "12569874") << endl;
	cout << setw(20) << left << "\"12569874\" > n5 ?" << boolalpha << setw(8) << ("12569874" > n5) << endl;
	cout << setw(20) << left << "n5 > 12569874 ?" << boolalpha << setw(8) << (n5 > 12569874) << endl;
	cout << setw(20) << left << "12569874 > n5 ?" << boolalpha << setw(8) << (12569874 > n5) << endl;
	cout << setw(14) << left << "n5 > n12 ?" << boolalpha << setw(8) << (n5 > n12) << endl << endl;

	cout << setw(14) << left << "n12 > n5 ?" << boolalpha << setw(8) << (n12 > n5) << endl;
	cout << setw(14) << left << "n12 > n7 ?" << boolalpha << setw(8) << (n12 > n7) << endl;
	cout << setw(14) << left << "n12 > n8 ?" << boolalpha << setw(8) << (n12 > n8) << endl;
	cout << setw(14) << left << "n12 > n11 ?" << boolalpha << setw(8) << (n12 > n11) << endl;
	cout << setw(14) << left << "n12 > n12 ?" << boolalpha << setw(8) << (n12 > n12) << endl;
	cout << setw(14) << left << "n12 > n13 ?" << boolalpha << setw(8) << (n12 > n13) << endl;
	cout << setw(14) << left << "n12 > n14 ?" << boolalpha << setw(8) << (n12 > n14) << endl << endl;

	cout << setw(14) << left << "n10 > n7 ?" << boolalpha << setw(8) << (n10 > n7) << endl;
	cout << setw(14) << left << "n10 > n10 ?" << boolalpha << setw(8) << (n10 > n10) << endl;
	cout << setw(14) << left << "n10 > n11 ?" << boolalpha << setw(8) << (n10 > n11) << endl;
	cout << setw(14) << left << "n10 > n14 ?" << boolalpha << setw(8) << (n10 > n14) << endl << endl;

	cout << "************************   3.Testing  operators <= and >= *********************" << endl << endl;

	cout << "n5 = " << n5 << endl;
	cout << "n6 = " << n6 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "n8 = " << n8 << endl;
	cout << "n9 = " << n9 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n11 = " << n11 << endl;
	cout << "n12 = " << n12 << endl;
	cout << "n13 = " << n13 << endl;
	cout << "n14 = " << n14 << endl << endl;

	cout << setw(14) << left << "n5 <= n5 ?" << boolalpha << setw(8) << (n5 <= n5) << endl;
	cout << setw(14) << left << "n5 <= n6 ?" << boolalpha << setw(8) << (n5 <= n6) << endl;
	cout << setw(14) << left << "n5 <= n9 ?" << boolalpha << setw(8) << (n5 <= n9) << endl;
	cout << setw(14) << left << "n5 <= n10 ?" << boolalpha << setw(8) << (n5 <= n10) << endl;
	cout << setw(14) << left << "n5 <= n12 ?" << boolalpha << setw(8) << (n5 <= n12) << endl;
	cout << setw(20) << left << "n5 <= 12569874 ?" << boolalpha << setw(8) << (n5 <= 12569874) << endl;
	cout << setw(20) << left << "12569874 <= n5 ?" << boolalpha << setw(8) << (12569874 <= n5) << endl;
	cout << setw(20) << left << "n5 <= \"12569874\" ?" << boolalpha << setw(8) << (n5 <= "12569874") << endl;
	cout << setw(20) << left << "\"12569874\" <= n5 ?" << boolalpha << setw(8) << ("12569874" <= n5) << endl << endl;
	cout << setw(14) << left << "n5 <= 0 ?" << boolalpha << setw(8) << (n5 <= 0) << endl << endl;

	cout << setw(14) << left << "n5 >= n5 ?" << boolalpha << setw(8) << (n5 >= n5) << endl;
	cout << setw(14) << left << "n5 >= n7 ?" << boolalpha << setw(8) << (n5 >= n7) << endl;
	cout << setw(14) << left << "n5 >= n9 ?" << boolalpha << setw(8) << (n5 >= n9) << endl;
	cout << setw(14) << left << "n5 >= n10 ?" << boolalpha << setw(8) << (n5 >= n10) << endl;
	cout << setw(14) << left << "n5 >= n12 ?" << boolalpha << setw(8) << (n5 >= n12) << endl;
	cout << setw(14) << left << "n5 >= 0 ?" << boolalpha << setw(8) << (n5 >= 0) << endl << endl;

	cout << setw(14) << left << "n12 >= n5 ?" << boolalpha << setw(8) << (n12 >= n5) << endl;
	cout << setw(14) << left << "n12 >= n7 ?" << boolalpha << setw(8) << (n12 >= n7) << endl;
	cout << setw(14) << left << "n12 >= n10 ?" << boolalpha << setw(8) << (n12 >= n10) << endl;
	cout << setw(14) << left << "n12 >= n11 ?" << boolalpha << setw(8) << (n12 >= n11) << endl;
	cout << setw(14) << left << "n12 >= n12 ?" << boolalpha << setw(8) << (n12 >= n12) << endl;
	cout << setw(14) << left << "n12 >= n14 ?" << boolalpha << setw(8) << (n12 >= n14) << endl;
	cout << setw(20) << left << "n5 >= 12569874 ?" << boolalpha << setw(8) << (n5 >= 12569874) << endl;
	cout << setw(20) << left << "12569874 >= n5 ?" << boolalpha << setw(8) << (12569874 >= n5) << endl;
	cout << setw(20) << left << "n5 >= \"12569874\" ?" << boolalpha << setw(8) << (n5 >= "12569874") << endl;
	cout << setw(20) << left << "\"12569874\" >= n5 ?" << boolalpha << setw(8) << ("12569874" >= n5) << endl << endl;
	cout << setw(14) << left << "n12 >= 0 ?" << boolalpha << setw(8) << (n12 >= 0) << endl << endl;

	cout << setw(14) << left << "n10 <= n5 ?" << boolalpha << setw(8) << (n10 <= n5) << endl;
	cout << setw(14) << left << "n10 <= n11 ?" << boolalpha << setw(8) << (n10 <= n11) << endl;
	cout << setw(14) << left << "n10 <= n12 ?" << boolalpha << setw(8) << (n10 <= n12) << endl;
	cout << setw(14) << left << "n10 <= 0 ?" << boolalpha << setw(8) << (n10 <= 0) << endl << endl;

	cout << "****************************   4.Testing  operators +  *************************" << endl << endl;

	cout << "n0 = " << n0 << endl;
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;
	cout << "n5 = " << n5 << endl;
	cout << "n6 = " << n6 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "n8 = " << n8 << endl;
	cout << "n9 = " << n9 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n11 = " << n11 << endl;
	cout << "n12 = " << n12 << endl;
	cout << "n13 = " << n13 << endl;
	cout << "n14 = " << n14 << endl << endl;

	cout << "n0 + n1 = " << (n0 + n1) << endl;
	cout << "n0 + 7654321 = " << (n0 + 7654321) << endl;
	cout << "7654321 + n0 = " << (7654321 + n0) << endl;
	cout << "n0 + 100000000000000000000001 = " << (n0 + "100000000000000000000001") << endl;
	cout << "100000000000000000000001 + n1 = " << ("100000000000000000000001" + n1) << endl << endl;

	cout << "n1 + n2 = " << (n1 + n2) << endl;
	cout << "n1 + n3 = " << (n1 + n3) << endl;
	cout << "n2 + n3 = " << (n2 + n3) << endl;

	cout << "n2 + 1 = " << (n2 + 1) << endl;
	cout << "n5 + n14 = " << (n5 + n14) << endl << endl;

	cout << "n8 + n12 = " << (n8 + n12) << endl;
	cout << "n13 + n12 = " << (n13 + n12) << endl << endl;

	cout << "****************************   5.Testing  operators -  *************************" << endl << endl;

	cout << "n0 = " << n0 << endl;
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;
	cout << "n5 = " << n5 << endl;
	cout << "n6 = " << n6 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "n8 = " << n8 << endl;
	cout << "n9 = " << n9 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n11 = " << n11 << endl;
	cout << "n12 = " << n12 << endl;
	cout << "n13 = " << n13 << endl;
	cout << "n14 = " << n14 << endl << endl;

	cout << "n0 - n1 = " << (n0 - n1) << endl;
	cout << "n0 - (-7654321) = " << (n0 - (-7654321)) << endl;
	cout << "(-7654321) - n0 = " << (-7654321 - n0) << endl;
	cout << "n0 - \"100000000000000000000001\" = " << (n0 - "100000000000000000000001") << endl;
	cout << "\"100000000000000000000001\" - n1 = " << ("100000000000000000000001" - n1) << endl << endl;

	cout << "n2 - n1 = " << (n2 - n1) << endl;
	cout << "n1 - n3 = " << (n1 - n3) << endl;
	cout << "n2 - n3 = " << (n2 - n3) << endl;

	cout << "n2 - 1 = " << (n2 - 1) << endl;
	cout << "n3 - 1 = " << (n3 - 1) << endl;
	cout << "n5 - n14 = " << (n5 - n14) << endl;

	cout << "n10 - n12 = " << (n10 - n12) << endl;
	cout << "n13 - n12 = " << (n13 - n12) << endl << endl;

	cout << "****************************   6.Testing  operators *  *************************" << endl << endl;

	cout << "n0 = " << n0 << endl;
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;
	cout << "n5 = " << n5 << endl;
	cout << "n6 = " << n6 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "n8 = " << n8 << endl;
	cout << "n9 = " << n9 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n11 = " << n11 << endl;
	cout << "n12 = " << n12 << endl;
	cout << "n13 = " << n13 << endl;
	cout << "n14 = " << n14 << endl << endl;

	cout << "n12 * 0 = " << n12 * 0 << endl;
	cout << "n12 * 1 = " << n12 * 1 << endl;
	cout << "n12 * 10 = " << n12 * 10 << endl;
	cout << "n12 * 11 = " << n12 * 11 << endl;
	//cout << "(abnromal test)! n12 * 100 = " << n12 * 100 << endl; 
	// this will exceed the max limit of HugeInt, thus generate error message

	cout << "n0 * n1 = " << n0 * n1 << endl;
	cout << "n1 * n8 = " << n1 * n8 << endl;
	cout << "123540 * n1 = " << 123540 * n1 << endl;
	cout << "-123540 * n1 = " << -123540 * n1 << endl;
	cout << "n1 * 123540 = " << n1 * 123540 << endl;
	cout << "\"-123540\" * n1 = " << "-123540" * n1 << endl;
	cout << "n1 * \"123540\" = " << n1 * "123540" << endl;

	cout << "n5 * 99 = " << n5 * 99 << endl;
	cout << "0 * n5 = " << 0 * n5 << endl;

	cout << "n14 * n8 = " << n14 * n8 << endl;

	cout << "****************************   6.Testing  operators /  *************************" << endl << endl;

	cout << "n0 = " << n0 << endl;
	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;
	cout << "n3 = " << n3 << endl;
	cout << "n4 = " << n4 << endl;
	cout << "n5 = " << n5 << endl;
	cout << "n6 = " << n6 << endl;
	cout << "n7 = " << n7 << endl;
	cout << "n8 = " << n8 << endl;
	cout << "n9 = " << n9 << endl;
	cout << "n10 = " << n10 << endl;
	cout << "n11 = " << n11 << endl;
	cout << "n12 = " << n12 << endl;
	cout << "n13 = " << n13 << endl;
	cout << "n14 = " << n14 << endl << endl;

	cout << "n0 / n1 = " << n0 / n1 << endl;
	cout << "n0 / 1249 = " << n0 / 1249 << endl;
	cout << "n0 / \"1249\" = " << n0 / "1249" << endl;

	cout << "923546959 / n0 = " << 923546959 / n0 << endl;
	cout << "92354695 / n0 = " << 92354695 / n0 << endl;
	cout << "\"923546959\" / n0 = " << "923546959" / n0 << endl;
	cout << "\"92354695\" / n0 = " << "92354695" / n0 << endl;

	cout << "n1 / n0 = " << n1 / n0 << endl;
	cout << "n1 / n8 = " << n1 / n8 << endl;
	cout << "n1 / n2 = " << n1 / n2 << endl;
	cout << "n1 / n0 = " << n1 / n0 << endl;

	cout << "n2 / n11 = " << n2 / n11 << endl;

	cout << "n5 / n14 = " << n5 / n14 << endl;
	cout << "n6 / n5 = " << n6 / n5 << endl;
	cout << "n6 / n7 = " << n6 / n7 << endl;

	cout << "\"88888888888888888888888888888\" / n6 = " << "88888888888888888888888888888" / n6 << endl;
	cout << "888 / n6 = " << "888" / n6 << endl;

	cout << "n7/ \"11111111111111111111111111111\" = " << n7 / "11111111111111111111111111111" << endl;
	cout << "n7/ 111 = " << n7 / "111" << endl;

	cout << "n11 / n2 = " << n11 / n2 << endl;
	cout << "n12 / n13 = " << n12 / n13 << endl;
	cout << "n13 / n14 = " << n13 / n14 << endl;	
	//this is an abnormal condition test, should output a error message
	cout << "n1 / 0 = " << n1 / 0 << endl << endl;

} // end main

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