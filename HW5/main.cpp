////////////////////////////////////////////////////////////////////////////////////////
// main.cpp
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 5
// Author: Wei Liu
// Date: 3/20/2015
// -----------------------------------------------------------------------------------
// Class descriptinon: 
// WordFont class will read a word that you input, and draw it on the screen with a 
// character height and width that you specify. 
// If the letters can't present in one line, they will show up in another line.
////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "WordFont.h"

using namespace std;

int main()
{
	WordFont wf; //instantiate an object
	wf.draw(); // do the drawing work
}