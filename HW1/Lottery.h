// -----------------------------------------------------------------------------------
// HomeWork 1
// Lottery.h
// This program allows the user to enter in the winning lottery number, as well as the
// lottery ticket number. The program should then print out if the player wins or lost.
// Author: Wei Liu
// Date: 1/29/2015
// ------------------------------------------------------------------------------------
#ifndef LOTTERY_H
#define LOTTERY_H
#include <iostream>

class Lottery
{
public:
	Lottery();//constructor
	void newTicket();//perform the required function in HW

private:
	int  winningLotteryNum; // the winning lottery number;
	int  lotteryTicketNum; // the lottery ticket number;
	int  correctNumbers; // how many correct numbers?

	void setWinningLotteryNum( int num ); //function to set winningLotteryNum;
	void setLotteryTicketNum( int num ); //function to set lotteryTicketNum;
	void setCorrectNumbers(int num); //function to set correctNumbers;
	void inputByUser(); // funcition prompts the user to input from keyboard;
	bool isContain( int singleDigit, int number ); // return true if the number contains the singleDigit;
	int  countRepeat( int number1, int number2 ); // count the how many repeat numbers of the two;
	void printResult() const; //define wheather the player wins or lost, and print on screen;
};

#endif