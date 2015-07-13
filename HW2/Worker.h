// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 2
// Worker.h
// Author: Wei Liu
// Date: 2/5/2015
// problem descriptinon: The class can prompt the user to enter the payCode(1-4) and call 
// the appropriate Worker method to calculate each employee¡¯s pay according to that employee¡¯s 
// paycode. Then the class can generate a bar chart representing the salaries.
// ------------------------------------------------------------------------------------

#ifndef WORKER_H
#define WORKER_H
#include <iostream>

class Worker
{
public:
	void enterPayCode(); // prompt the user input a number
private:
	double managerSalary = 0; // weekly salary of manager
	double hourlyWorkerSalary = 0; // weekly salary of hourly worker
	double commissionWorkerSalary = 0; // weekly salary of commission worker
	double pieceWorkerSalary = 0; // weekly salary of piece worker

	void setVal(double & inputVal); // input filter, to make sure the user input is valid
	void manager(); // function to compute manager's salary
	void hourlyWorker(); // function to compute hourly worker's salary
	void commissionWorker(); // function to compute commission worker's salary
	void pieceWorker(); // function to compute piece worker's salary
	void printStars(const double num); // convert num to integer, then print stars
	void printBarChart(); // private function to show the bar chart
};

#endif