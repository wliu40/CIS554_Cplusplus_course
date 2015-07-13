////////////////////////////////////////////////////////////////////////////////////////
// SetTest.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 6
// Author: Wei Liu
// Date: 3/28/2015
// -----------------------------------------------------------------------------------
// cpp descriptinon: 
// This is a test cpp for the class Set.
// Different boundary conditions and the overloading constructor of the class Set was
// tested.
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include "Set.h"
using namespace std;
int main()
{
	cout << "Test when there are single or no element in a Set.\n" << endl;
	vector<int> v0 = { 0 };
	Set s0(v0);
	cout << "The Set s0 contains: ";
	s0.print();

	vector<int> v1 = { 20 };
	Set s1(v1);	
	cout << "The Set s1 contains: ";
	s1.print();

	vector<int> v2 = {  }; // v2 is a empty set
	Set s2(v2);
	cout << "The Set s2 contains(s2 is a empty Set): ";
	s2.print();

	s0.Union(s1);
	cout << "After Union with s1, the Set s0 now contains: ";
	s0.print();
	cout << "------------------------------------------------------------" << endl;

	s0.Intersection(s1);
	cout << "After Intersection with s1, the Set s0 now contains: ";
	s0.print();
	cout << "------------------------------------------------------------" << endl;

	s0.Union(s2);
	cout << "After Union with s2, the Set s0 now contains: ";
	s0.print();
	cout << "------------------------------------------------------------" << endl;

	s0.Intersection(s2);
	cout << "After Intersection with s2, the Set s0 now contains: ";
	s0.print();
	cout << "------------------------------------------------------------" << endl;

	cout << "Set s1 now contains(s1 should not change): ";
	s1.print();
	cout << "------------------------------------------------------------" << endl;

	cout << "Set s2 now contains(s2 should not change): ";
	s2.print();
	cout << "\n\n************************************************************" << endl;	

	cout << "Test when there are multiple elements in a Set.\n" << endl;
	Set s4(vector<int>{0, 1, 5, 7, 10, 12, 17, 20});
	Set s5(vector<int>{0, 3, 9, 11, 17, 18, 20});
	Set s6(vector<int>{0, 7, 8, 11, 12, 19, 20});
	cout << "The Set s4 contains: ";
	s4.print();
	cout << "The Set s5 contains: ";
	s5.print();
	cout << "The Set s6 contains: ";
	s6.print();

	s4.Union(s5);
	cout << "After Union with s5, the Set s4 now contains: ";
	s4.print();
	cout << "------------------------------------------------------------" << endl;

	s4.Intersection(s6);
	cout << "After Intersection with s6, the Set s4 now contains: ";
	s4.print();
	cout << "------------------------------------------------------------" << endl;

	cout << "Set s5 now contains(s5 should not change): ";
	s5.print();
	cout << "------------------------------------------------------------" << endl;

	cout << "Set s6 now contains(s6 should not change): ";
	s6.print();
	cout << "\n\n************************************************************"<< endl;

	cout << "Test the overloading constructor for the class Set.\n" << endl;
	Set s7(0, 5); // create a Set contains 0,1,2,3,4,5
	cout << "The Set s7 contains(constructor overloading): ";
	s7.print();

	Set s8(0, 20); // create a Set contains from 0 to 20
	cout << "The Set s8 contains(constructor overloading): ";
	s8.print();

	Set s9(1, 1); // create a Set contains 1
	cout << "The Set s9 contains(constructor overloading): ";
	s9.print();
}