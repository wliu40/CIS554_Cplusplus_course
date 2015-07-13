///////////////////////////////////////////////////////////////////////////////
// TimeStamp_Test.cpp
//
// This is a simple test program of the TimeStamp Class
//
// Author: Joe Waclawski
// Purpose: CIS554 
///////////////////////////////////////////////////////////////////////////////

#include "TimeStamp.h" // TimeStamp class
#include <cstdlib> // system
#include <ctime> // time
#include <iostream> // cin, cout
#include <windows.h> // Sleep

using std::cout;
using std::endl;

void main()
{
	// local variables
	string timeString;
	TimeStamp ts;
	unsigned sleepTime;

	// seed random number generator with current integer time
	srand(static_cast<unsigned int>(time(0)));


	// call TimeStamp object to get current time
	timeString=ts.GetTime();
	// print current time
	cout << timeString << endl;

	// loop through a few times to test to make sure that time
	// is actually moving forward, 
	for (int i=0; i<10;i++)
	{
		// select a random time to sleep between 100 milliseconds
		// at 2 seconds
		sleepTime = 100+rand()%2000;
        cout << "Sleeping for " << sleepTime << " milliseconds" << endl;

		// call Windows Sleep function to sleep. Windows OS dependent
		Sleep(sleepTime);

		// get the current time
		timeString=ts.GetTime();
		// print current time
		cout << timeString << endl;
	}

	// call system command to invoke system pause. DOS OS dependent
	system ("pause");
}


