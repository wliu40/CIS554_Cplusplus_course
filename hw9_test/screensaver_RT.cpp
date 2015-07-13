///////////////////////////////////////////////////////////////////////
//// screensaver.cpp
//// Author: Joe Waclawski
//// Description: Simple screensaver to demonstrate MyRect class
///////////////////////////////////////////////////////////////////////
//#include "MyRect.h"
//#include "MyTriangle.h"
//#include "MyCircle.h"
//#include <stdlib.h> // rand and srand
//#include <time.h> // time funciton
//#include <windows.h>  // POINT object
//#include <map>
//#include <vector>
//#include <string>
//
//
//// how many times will the program cycle
//#define PROGRAM_RUN 20
//
//// small delay between drawing rectangles during each run
//#define DRAW_DELAY 100
//
//// small delay between each iteration of drawing rectangles
//#define ITERATION_DELAY 250
//
//#define NUM_SHAPES 1
//
//// function prototypes
//void RandomAttributes(MyRect &S);
//void RandomAttributes(MyTriangle &S);
//void RandomAttributes(MyCircle &S);
//void RandomAttributes(Shape *S);
//void display(vector<Shape*>shapeVector, int index);
//
//void main()
//{
//	int shapes; // loop index
//
//	// seed the random number generator
//	srand((unsigned int)time(0));
//
//	// allow the user time to move the console window away
//	// from the FilledShapes window are
//	cout << "Move this window to the lower right of the screen, and press ENTER to continue:\n";
//	cin.get();
//
//
//	// Create the rectangles
//	//MyRect R[NUM_SHAPES];
//	//MyTriangle T[NUM_SHAPES];
//	//MyCircle C[NUM_SHAPES];
//
//	vector <Shape*> recPtrs;
//	vector <Shape*> trianglePtrs;
//	vector <Shape*> circlePtrs;
//
//	map < string, vector<Shape*> > shapeMap;
//
//	shapeMap.insert(make_pair("rectangle", recPtrs));
//	shapeMap.insert(make_pair("triangle", trianglePtrs));
//	shapeMap.insert(make_pair("circle", circlePtrs));
//	
//	Shape *randomShape;
//	for (int i = 0; i < 150; i++)
//	{
//		
//		int randomNum = rand() % 3;
//
//		if (randomNum == 0)
//			randomShape = new MyRect();
//		else if (randomNum == 1)
//			randomShape = new MyTriangle();
//		else
//			randomShape = new MyCircle();
//
//		RandomAttributes(randomShape);//多态， 融合三个function
//	//	(*randomShape).ClearScreen();
//
//		//recPtrs.push_back(randomShape);
//		//shapeMap["rectangle"].push_back(randomShape);
//
//
//		// declare pointers for downcasting
//		MyRect *recPtr;
//		MyTriangle *triPtr;
//		MyCircle *cirPtr;
//
//		// downcasting is done here
//		recPtr = dynamic_cast<MyRect *>(randomShape);
//		triPtr = dynamic_cast<MyTriangle *>(randomShape);
//		cirPtr = dynamic_cast<MyCircle *>(randomShape);
//
//		// after downcasting, we have determined which drived object type 
//		// we have and we can call that specific function on the derived class
//		// through the base class pointer. Slick!!
//		if (recPtr != NULL)
//			shapeMap["rectangle"].push_back(randomShape);
//		if (triPtr != NULL)
//			shapeMap["triangle"].push_back(randomShape);
//		if (cirPtr != NULL)
//			shapeMap["circle"].push_back(randomShape);
//
//
//		//for (shapes = 0; shapes < NUM_SHAPES; shapes++)
//		//{
//		//	randomShape->Draw();
//		//	if (DRAW_DELAY > 0)
//		//		Sleep(DRAW_DELAY);
//		//}
//
//		//// wait for a little while 
//		//if (ITERATION_DELAY > 0)
//		//	Sleep(ITERATION_DELAY);
//		
//	}
//
//	for (int i = 0; i < 30; i++)
//	{
//		(*randomShape).ClearScreen();
//		display(shapeMap["rectangle"], i);
//		display(shapeMap["triangle"], i);
//		display(shapeMap["circle"], i);
//	}
//	
//	//for (int j = 0; j < recPtrs.size(); j++)
//	//{
//	//	recPtrs[0]->ClearScreen();
//	//	recPtrs[j]->Draw();
//	//	if (DRAW_DELAY > 0)
//	//		Sleep(DRAW_DELAY);
//
//	//	if (ITERATION_DELAY > 0)
//	//		Sleep(ITERATION_DELAY);
//	//}
//	
//
//	delete randomShape;
//
//	//vector <Shape*> rectanglePtrs;
//	//vector <Shape*> trianglePtrs;
//	//vector <Shape*> circlePtrs;
//	//map < string, vector<Shape*> > m;
//
//	//m.insert(make_pair("rectangle", rectanglePtrs));
//	//m.insert(make_pair("triangle", trianglePtrs));
//	//m.insert(make_pair("circle", circlePtrs));
//
//	//MyRect *R = new MyRect();
//	////MyTriangle T;
//	////MyCircle C;
//
//
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	(*R).ClearScreen();
//	//	
//	//	RandomAttributes(*R);
//	//	//RandomAttributes(T);
//	//	//RandomAttributes(C);
//
//	//	m["rectangle"].push_back(R);
//
//	//		// draw all the shapes
//	//	for (shapes = 0; shapes < NUM_SHAPES; shapes++)
//	//	{	
//	//		R[shapes].Draw();
//	//		//T[shapes].Draw();
//	//		//C[shapes].Draw();
//
//	//		if (DRAW_DELAY > 0)
//	//			Sleep(DRAW_DELAY);
//	//	}
//
//	//	// wait for a little while 
//	//	if (ITERATION_DELAY > 0)
//	//		Sleep(ITERATION_DELAY);
//
//	//}
//
//	//for (int i=0; i<PROGRAM_RUN; i++)
//	//{
//	//	// clear the window
//	//	// note that I can use ANY instance of a MyRect
//	//	// object to clear the window
//
//	//	R[0].ClearScreen();	
//
//	//	// choose random parameters for each rectangle
//	//	for (shapes = 0; shapes < NUM_SHAPES; shapes++)
//	//	{	
//	//		RandomAttributes(R[shapes]);
//	//		RandomAttributes(T[shapes]);
//	//		RandomAttributes(C[shapes]);
//	//	}
//
//
//	//	// draw all the shapes
//	//	for (shapes = 0; shapes < NUM_SHAPES; shapes++)
//	//	{	
//	//		R[shapes].Draw();
//	//		T[shapes].Draw();
//	//		C[shapes].Draw();
//
//	//		if (DRAW_DELAY > 0)
//	//			Sleep(DRAW_DELAY);
//	//	}
//
//	//	// wait for a little while 
//	//	if (ITERATION_DELAY > 0)
//	//		Sleep(ITERATION_DELAY);
//	//}
//
//}
//
//void display(vector<Shape*> shapeVector, int index)
//{
//	if (index < shapeVector.size())
//	{
//		shapeVector[index]->Draw();
//		if (DRAW_DELAY > 0)
//			Sleep(DRAW_DELAY);
//
//		if (ITERATION_DELAY > 0)
//			Sleep(ITERATION_DELAY);
//	}
//}
//
//
//void RandomAttributes(Shape *shapePtr)
//{
//	// declare pointers for downcasting
//	MyRect *recPtr;
//	MyTriangle *triPtr;
//	MyCircle *cirPtr;
//
//	// downcasting is done here
//	recPtr = dynamic_cast<MyRect *>(shapePtr);
//	triPtr = dynamic_cast<MyTriangle *>(shapePtr);
//	cirPtr = dynamic_cast<MyCircle *>(shapePtr);
//
//	// after downcasting, we have determined which drived object type 
//	// we have and we can call that specific function on the derived class
//	// through the base class pointer. Slick!!
//	if (recPtr != NULL)
//		RandomAttributes(*recPtr);
//	if (triPtr != NULL)
//		RandomAttributes(*triPtr);
//	if (cirPtr != NULL)
//		RandomAttributes(*cirPtr);
//
//}
//
//
//
//
//
//
//
//
///////////////////////////////////////////////////////////////////////
//// RandomAttributes
//// Description: This routine will randomy choose parameters for 
////              a MyRect object, and draw it.
//// 
//// Inputs: MyRect object
//// Outputs: None
//// Returns: None
///////////////////////////////////////////////////////////////////////
//void RandomAttributes(MyRect &S)
//{
//	// needed to draw a filled shape
//	POINT p;
//	p.x=50;
//	p.y=50;
//
//	// define variables that will hold the parameters
//	// for the rectangle
//	SHAPE_COLOR firstColor=RED;
//	SHAPE_COLOR lastColor=PURPLE;
//	unsigned int myPen;
//	unsigned int myBrush;
//	unsigned int length;
//	unsigned int width;
//
//	// reset the rectangle object to some known, legal values
//	S.SetPosition(p);
//	S.SetLength(S.GetWindowHeight()/10);
//	S.SetWidth(S.GetWindowWidth()/10);
//
//	// generate random values for our parameters, within
//	// allowable limits
//	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//
//	// make sure the pen and brush colors are not the same
//	do {
//		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//	} while (myBrush == myPen);
//
//	// set up the parameters of the filled shape
//	// object per the random data
//	S.SetBorderColor((SHAPE_COLOR)myPen);
//	S.SetFillColor((SHAPE_COLOR)myBrush);
//
//	// stay in each loop until you have chosen random
//	// parameters which draw a rectangle within the legal
//	// limits of the window.
//
//	// length
//	do {
//		length = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetLength(length));
//
//	// width
//	do {
//		width = 1 + rand() % S.GetWindowWidth();
//	} while(!S.SetWidth(width));
//
//	// position
//	do {
//		p.x = 1 + rand() % S.GetWindowWidth();
//		p.y = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetPosition(p));
//}
//
//
//
///////////////////////////////////////////////////////////////////////
//// RandomAttributes
//// Description: This routine will randomy choose parameters for 
////              a MyTriangle object, and draw it.
//// 
//// Inputs: MyTriangle object
//// Outputs: None
//// Returns: None
///////////////////////////////////////////////////////////////////////
//void RandomAttributes(MyTriangle &S)
//{
//	// needed to draw a filled shape
//	POINT p;
//	p.x=50;
//	p.y=50;
//
//	// define variables that will hold he parameters
//	// for the rectangle
//	SHAPE_COLOR firstColor=RED;
//	SHAPE_COLOR lastColor=PURPLE;
//	unsigned int myPen;
//	unsigned int myBrush;
//	unsigned int length;
//
//	// reset the rectangle object to some known, legal values
//	S.SetPosition(p);
//	S.SetLength(S.GetWindowHeight()/10);
//
//	// generate random values for our parameters, within
//	// allowable limits
//	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//
//	// make sure the pen and brush colors are not the same
//	do {
//		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//	} while (myBrush == myPen);
//
//	// set up the parameters of the filled shape
//	// object per the random data
//	S.SetBorderColor((SHAPE_COLOR)myPen);
//	S.SetFillColor((SHAPE_COLOR)myBrush);
//
//	// stay in each loop until you have chosen random
//	// parameters which draw a rectangle within the legal
//	// limits of the window.
//
//	// length
//	do {
//		length = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetLength(length));
//
//	// position
//	do {
//		p.x = 1 + rand() % S.GetWindowWidth();
//		p.y = 1 + rand() % S.GetWindowHeight();
//	} while(!S.SetPosition(p));
//}
//
//
///////////////////////////////////////////////////////////////////////
//// RandomAttributes
//// Description: This routine will randomy choose parameters for 
////              a MyCircle object, and draw it.
//// 
//// Inputs: MyCircle object
//// Outputs: None
//// Returns: None
///////////////////////////////////////////////////////////////////////
//void RandomAttributes(MyCircle &circle)
//{
//	// needed to draw a filled shape
//	POINT p;
//	p.x = 50;
//	p.y = 50;
//
//	// define variables that will hold the parameters
//	// for the rectangle
//	SHAPE_COLOR firstColor = RED;
//	SHAPE_COLOR lastColor = PURPLE;
//	unsigned int myPen;
//	unsigned int myBrush;
//	unsigned int radius;
//
//
//	// reset the rectangle object to some known, legal values
//	circle.SetPosition(p);
//	circle.SetRadius(circle.GetWindowHeight() / 10);
//
//
//	// generate random values for our parameters, within
//	// allowable limits
//	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//
//	// make sure the pen and brush colors are not the same
//	do {
//		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
//	} while (myBrush == myPen);
//
//	// set up the parameters of the filled shape
//	// object per the random data
//	circle.SetBorderColor((SHAPE_COLOR)myPen);
//	circle.SetFillColor((SHAPE_COLOR)myBrush);
//
//	// stay in each loop until you have chosen random
//	// parameters which draw a radius within the legal
//	// limits of the window.
//
//	// radius
//	do {
//		radius = 1 + rand() % circle.GetWindowHeight();
//	} while ( !circle.SetRadius(radius) );
//
//
//	// position
//	do {
//		p.x = 1 + rand() % circle.GetWindowWidth();
//		p.y = 1 + rand() % circle.GetWindowHeight();
//	} while ( !circle.SetPosition(p) );
//}
//
//
