
////////////////////////////////////////////////////////////////////////////////////////
// ScreenSaver.h
// -----------------------------------------------------------------------------------
// Course: CIS554
// HomeWork 9
// Author: Wei Liu
// Date: 5/5/2015
// -----------------------------------------------------------------------------------
// Description -  Class ScreenSaver provides a screen saver program
//				  This program will output ramdom generated triangle, rectangle, circle 
//   			  with different filled colors and board colors.
//				  This file is a the header file of this class
////////////////////////////////////////////////////////////////////////////////////////


#ifndef _SCREENSAVER_H
#define _SCREENSAVER_H

#include "MyRect.h"
#include "MyTriangle.h"
#include "MyCircle.h"
#include <stdlib.h> // rand and srand
#include <time.h> // time funciton
#include <windows.h>  // POINT object
#include <map>
#include <vector>
#include <string>

using namespace std;

class ScreenSaver
{
public:
	ScreenSaver();//constructor
	~ScreenSaver();//destructor
	void run();//funtion to perform the task
private:

	const int NUM_SHAPES; // how many random shapes will be created
	const int ITERATION_DELAY; // small delay between each iteration of drawing rectangles
	const int DRAW_DELAY; // small delay between drawing rectangles during each run


	Shape *randomShape; // a shape class pointer

	// create vector of shape pointers to store shapes
	vector <Shape*> recPtrs;
	vector <Shape*> trianglePtrs;
	vector <Shape*> circlePtrs;

	//create a map to store random shapes
	map < string, vector<Shape*> > shapeMap;

	// Multiple RandomAttributes functions combined into a single function
	void RandomAttributes(Shape *S);

	// overloading function for each type of shape
	void RandomAttributes(MyRect &S);
	void RandomAttributes(MyTriangle &S);
	void RandomAttributes(MyCircle &S);

	// display a single shape each time
	void displaySingleShape(vector<Shape*>shapeVector, int index);

};

#endif