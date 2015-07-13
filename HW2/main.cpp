// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 2
// main.cpp
// Author: Wei Liu
// Date: 2/5/2015
// problem descriptinon: The class can prompt the user to enter the payCode(1-4) and call 
// the appropriate Worker method to calculate each employee¡¯s pay according to that employee¡¯s 
// paycode. Then the class can generate a bar chart representing the salaries.
// ------------------------------------------------------------------------------------

#include <iostream>
#include "Worker.h"

using namespace std;
int main()
{
	Worker wk; // creat an instance of class Worker
	wk.enterPayCode(); // prompt the user to input the payCode and caculate the salary accordingly
	return 0;
}