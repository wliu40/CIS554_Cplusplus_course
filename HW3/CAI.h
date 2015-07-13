#ifndef CAI_H
#define CAI_H
#include <iostream>

class CAI
{
public:
	CAI();//Constructor
	void StartTest();//Start the test

private:
	unsigned problemSize; //how many questions for mutiplication and division problems?
	unsigned firstTryForMulQues; //how many times they are right in the first try for multiply problem?
	unsigned firstTryForDivQues; //how many times they are right in the first try for division problem?
	unsigned tryForMulQues; //how many times do they tried for each multiply problem?
	unsigned tryForDivQues; //how many times do they tried for each division problem?

	void AskRandomMultiplicationQuestion(); //private function that asks a multiply question
	void AskRandomDivisionQuestion(); //private function that asks a division question

	void PrintRandomGoodJob(); //private function that prints a random positive message
	void PrintRandomEncouragementMessage(); //private function that prints a random motivation message
	int  ChooseRandomNumber(const int num); //private member function that returns a random number
	void PrintTestSummary(); //private member function that prints a summary of how they did

};

#endif