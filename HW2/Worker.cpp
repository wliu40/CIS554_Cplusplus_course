// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 2
// Worker.cpp
// Author: Wei Liu
// Date: 2/5/2015
// problem descriptinon: The class can prompt the user to enter the payCode(1-4) and call 
// the appropriate Worker method to calculate each employee¡¯s pay according to that employee¡¯s 
// paycode. Then the class can generate a bar chart representing the salaries.
// ------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Worker.h"

using std::cout;
using std::cin;
using std::endl;
using std::round;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;

//prompt the user to input the paycode, and switch to the according worker functions.
void Worker::enterPayCode()
{

	int payCode = 1; //initial the payCode to manager
	while (payCode != -1) //when payCode == -1, terminated the while loop
	{
		cout << "Enter paycode (-1 to end): ";
		if (!(cin >> payCode)) // if the input is not an integer, !(cin >> payCode) will return 'true'
		{
			cout << "\n[Error]: Please only input integer number!\n" << endl;
			cin.clear(); // clean the condition state of cin
			while (cin.get() != '\n'); //'rinse' the remaining chars in stream, exaust until '\n'
			continue;
		}
		switch (payCode) //if input is a integer, switch to the appropriate function
		{
			case 1:
				manager();
				break;
			case 2:
				hourlyWorker();
				break;
			case 3:
				commissionWorker();
				break;
			case 4:
				pieceWorker();
				break;
			case -1:
				break; // if input == -1, do nothing
			default: // if the user input is not 1 to 4 or -1, remind the user
				cout << "\n[Error]: Valid input is integer 1 through 4, or -1, please check." << endl;
				break; // for the convenience of future edit, keep the break here
		}
		cout << endl;
	}
	cout << "--------------Salary Bar Chart--------------" << endl;
	printBarChart();// using a private utility function generate the bar chart
	cout << endl;
}
//input filter, to make sure the input is valid (for this instance, the input should be a positive double number)
void Worker::setVal(double &val)
{
	while (1)
	{
		if (!(cin >> val)) //if the input is not number of double type (eg: char or string)
		{
			cout << "\n[Error]: input a number!" << endl;
			cin.clear();
			while (cin.get() != '\n'); // exaust the cin stream, until meet '\n'
			cout << "input again: ";
			continue;
		}
		if (val < 0.0)// if the input is a negtive number
		{
			cout << "\n[Error]: input a positive number!" << endl;
			cout << "input again: ";
			continue;
		}
		return; // if the input is positive double number, return
	}
}
//private function, caculate the manager's salary.
void Worker::manager()
{
	cout << "Manager selected." << endl;
	cout << "Enter weekly salary: ";
	setVal(managerSalary);
	cout << "Manager's pay is $" << fixed << setprecision(2) << managerSalary << endl;
}
//private function, caculate the hourly worker's salary.
void Worker::hourlyWorker()
{
	double hourlySalary;
	double hoursWorked;
	cout << "Hourly worker selected." << endl;
	cout << "Enter the hourly salary: ";
	setVal(hourlySalary);
	cout << "Enter the total hours worked: ";
	setVal(hoursWorked);
	if ( hoursWorked <= 40.0 )//if the worked hours within 40 hours.
		hourlyWorkerSalary = hourlySalary * hoursWorked;
	else// if the worker worked more than 40 hours.
		hourlyWorkerSalary = hourlySalary * 40.0 + 1.5 * hourlySalary * ( hoursWorked - 40.0 );
	cout << "Hourly worker's pay is $" << fixed << setprecision(2) << hourlyWorkerSalary << endl;
}
//private function, caculate the commission worker's salary.
void Worker::commissionWorker()
{
	double grossWeeklySales;
	cout << "Commission worker selected." << endl;
	cout << "Enter gross weekly sales: ";
	setVal(grossWeeklySales);
	commissionWorkerSalary = 250.0 + grossWeeklySales * 0.057;
	cout << "Commission worker's pay is $" << fixed << setprecision(2) << commissionWorkerSalary << endl;
}
//private function, caculate the piece worker's salary.
void Worker::pieceWorker()
{
	double numberOfPieces;
	double wagePerPiece;
	cout << "Pieceworker selected." << endl;
	cout << "Enter number of pieces: ";
	setVal(numberOfPieces);
	cout << "Enter wage per piece: ";
	setVal(wagePerPiece);
	pieceWorkerSalary = wagePerPiece * numberOfPieces;
	cout << "Pieceworker's pay is $" << fixed << setprecision(2) << pieceWorkerSalary << endl;
}
//private function, print #num of stars
void Worker::printStars(const double num)
{
	int numOfStars = static_cast<int>( round(num / 100.0) ); // round the data to the nearest hundreds
	for (int i = 0; i < numOfStars; i++)
	{
		cout << "*";
	}
	cout << endl;
}
// using a private utility function generate the bar chart
void Worker::printBarChart() 
{
	cout << setw(15) << left << "Managers";
	printStars(managerSalary);

	cout << setw(15) << left << "Hourly";
	printStars(hourlyWorkerSalary);

	cout << setw(15) << left << "Commission";
	printStars(commissionWorkerSalary);

	cout << setw(15) << left << "Pieceworker";
	printStars(pieceWorkerSalary);
}