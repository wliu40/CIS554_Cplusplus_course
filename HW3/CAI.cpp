#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "CAI.h"
using namespace std;

//Constructor,set the private member variables as initially 0;
CAI::CAI()
{
	problemSize = 5; //we have 5 multiplication question, 5 division questions
	firstTryForMulQues = 0;
	firstTryForDivQues = 0;
	tryForMulQues = 0;
	tryForDivQues = 0;
}

void CAI::StartTest() //public method provide to carry out the test
{
	srand(time(0)); //make sure srand has different seed, so as to make the rand() generate different numbers each time
	for (unsigned i = 1; i <= problemSize; ++i) //5 questions
	{
		cout << "********* Multiplication problem [ " << i << " ] *********" << endl;

		AskRandomMultiplicationQuestion();
		cout << endl;
	}

	for (unsigned i = 1; i <= problemSize; ++i)//another 5 questions
	{	
		cout << "********* Division problem [ " << i << " ] *********" <<  endl;
		AskRandomDivisionQuestion();
		cout << endl;
	}
	PrintTestSummary();
}

void CAI::AskRandomMultiplicationQuestion()
{	
	int factor1 = ChooseRandomNumber(10);//a random number for factor1
	int factor2 = ChooseRandomNumber(10);//another random number for factor2
	bool flag = true;//use to determine if the first try get the corret answer

	cout << "How much is " << factor1 << " times " << factor2 << " ?" << endl;
	cout << "Input you answer: ";
	int answer;
	cin >> answer;
	while ( 1 ) //continue the loop until get a correct answer
	{
		if (answer == factor1 * factor2)
		{
			if (flag)//if flag has not been changed			
				firstTryForMulQues++;//we have a correct answer at the first try!
			PrintRandomGoodJob();//print random greetings
			break;//out the loop
		}
		else
		{
			flag = false; //flag will be false if it was not true in the first loop
			tryForMulQues += 1;			
			PrintRandomEncouragementMessage();
			cout << "Input you answer: ";
			cin >> answer;
		}
	}	
}
void CAI::AskRandomDivisionQuestion()
{

	int dividend = ChooseRandomNumber(10);//possible value: 0-9
	int divisor = ChooseRandomNumber(10);//possible value: 0-9
	while (divisor == 0) //if the divisor is zero, choose again(until not zero)
		divisor = ChooseRandomNumber(10);

	int answer;
	bool flag = true; //used to determine if the first try get the corret answer

	cout << "How much is " << dividend << " divided by " << divisor << " ?" << endl;
	cout << "Input you answer: ";
	cin >> answer;
	while ( 1 )
	{
		if (answer == dividend / divisor) //if the answer is correct
		{
			if (flag) //if flag has not been changed
				firstTryForDivQues++;//we have a correct answer at the first try!
			PrintRandomGoodJob();//print greeting
			break;//out the loop
		}
		else
		{
			flag = false; //flag will be false if it was not true in the first loop
			tryForDivQues += 1; //we have a wrong guess
			PrintRandomEncouragementMessage(); //print encouragement
			cout << "Input you answer: ";
			cin >> answer;
		}
	}	
}

int CAI::ChooseRandomNumber(const int num)
{
	return rand() % num; //generate a random integer number from 0 to num-1
}

void CAI::PrintRandomGoodJob()
{
	cout << endl;
	int random = ChooseRandomNumber(4); //possible value: 0,1,2,3
	switch (random + 1) //switch to different 'good job' greeting randomly
	{
	case 1:
		cout << "Very good!" << endl;
		break;
	case 2:
		cout << "Excellent!" << endl;
		break;
	case 3:
		cout << "Nice work!" << endl;
		break;
	default:
		cout << "Keep up the good work!" << endl;
		break;
	}
	cout << endl;
}

void CAI::PrintRandomEncouragementMessage()
{
	cout << endl;
	int random = ChooseRandomNumber(4);//possible value: 0,1,2,3
	switch (random + 1) //switch to different encouragement randomly
	{
	case 1:
		cout << "No. Please try again." << endl;
		break;
	case 2:
		cout << "Wrong. Try once more." << endl;
		break;
	case 3:
		cout << "Don't give up!" << endl;
		break;
	default:
		cout << "No. Keep trying." << endl;
		break;
	}
	cout << endl;
}

//private member function that prints a summary of how the students did
//how many they got right on the first try, and how many wrong guesses it took, 
//on average, to get each of the other ones correct.
void CAI::PrintTestSummary()
{
	cout << "\n-------------Multiplication Problems Report-------------" << endl;
	cout << "There are " << firstTryForMulQues << " times you've got right at the first try!" << endl;
	cout << "On average there are " << fixed << setprecision(2) << static_cast<double>(tryForMulQues) / problemSize;
	cout << " wrong guesses to get the correct answer!" << endl;

	cout << "\n----------------Division Problems Report----------------" << endl;
	cout << "There are " << firstTryForDivQues << " times you've got right at the first try!" << endl;
	cout << "On average there are " << fixed << setprecision(2) << static_cast<double>(tryForDivQues) / problemSize;
	cout << " wrong guesses to get the correct answer!" << endl;
	cout << endl;
}