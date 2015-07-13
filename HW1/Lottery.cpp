// -----------------------------------------------------------------------------------
// HomeWork 1
// Lottery.cpp
// This program allows the user to enter in the winning lottery number, as well as the
// lottery ticket number. The program should then print out if the player wins or lost.
// Author: Wei Liu
// 1/29/2015
// -----------------------------------------------------------------------------------

#include <iostream>
#include "Lottery.h"

using std::cout;
using std::cin;
using std::endl;

//constructor
Lottery::Lottery()
{
	winningLotteryNum = 0;
	lotteryTicketNum = 0;
	correctNumbers = 0;
}
//functions to access the private values
void Lottery::setWinningLotteryNum( int num )
{
	winningLotteryNum = num;
}
void Lottery::setLotteryTicketNum( int num )
{
	lotteryTicketNum = num;
}
void Lottery::setCorrectNumbers(int num)
{
	correctNumbers = num;
}
//input the Winning lottery number and ticket number by user
void Lottery::inputByUser()
{
	int num;

	cout << "Enter Winning Lottery Number(5 digits, "
		 << "no digit repeated, first number cannot be 0): ";
	cin >> num;
	setWinningLotteryNum( num );

	cout << "Enter Ticket Number(5 digits, "
		 << "no digit repeated, first number cannot be 0): ";
	cin >> num;
	setLotteryTicketNum( num );
}
//return true if the number contains the singleDigit, otherwise return false;
bool Lottery::isContain( int singleDigit, int number )
{
	while ( number > 0 )
	{
		if ( singleDigit == number % 10 )
			return true;
		number /= 10;
	}
	return false;
}
//count how many same numbers in numnber1 and number2
int Lottery::countRepeat( int number1, int number2 )
{
	int counter = 0;
	while ( number1 > 0 )
	{
		if ( isContain( number1 % 10, number2 ) )
			counter++;
		number1 /= 10;
	}
	return counter;
}
//show the final results weather the user wins or lose
void Lottery::printResult() const
{
	if ( correctNumbers < 3 )
		cout << "Sorry, you lose. Try again tomorrow!" << endl;
	else if ( correctNumbers == 3 )
		cout << "You Win $1,000. Congratulations!!" << endl;
	else if ( correctNumbers == 4 )
		cout << "You Win $10,000. Congratulations!!" << endl;
	else
		cout << "You Win $1,000,000. Congratulations!!" << endl;
}
//generate a new ticket, input the two numbers, and show the lottery result
void Lottery::newTicket()
{
	inputByUser();
	setCorrectNumbers ( countRepeat( winningLotteryNum, lotteryTicketNum ) );
	printResult();
}
