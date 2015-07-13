
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
//				  This file is a the implement file of this class.
////////////////////////////////////////////////////////////////////////////////////////


#include "ScreenSaver.h"

/////////////////////////////////////////////////////////////////////
// ScreenSaver
// Description: class default contructor
// Inputs: None
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
ScreenSaver::ScreenSaver() : DRAW_DELAY(100), ITERATION_DELAY(250), NUM_SHAPES(150)
{
	//insert the pairs into the map
	shapeMap.insert(make_pair("rectangle", recPtrs));
	shapeMap.insert(make_pair("triangle", trianglePtrs));
	shapeMap.insert(make_pair("circle", circlePtrs));
}

/////////////////////////////////////////////////////////////////////
// ~ScreenSaver
// Description: class destructor,delete the shape pointer of randomShape
// Inputs: None
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
ScreenSaver::~ScreenSaver()
{
	delete randomShape;
}

/////////////////////////////////////////////////////////////////////
// displaySingleShape
// Description: display the shape obj in the shapeVector at the index 
//				position
// Inputs: vector<Shape*> shapeVector, int index
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void ScreenSaver::displaySingleShape(vector<Shape*> shapeVector, int index)
{
	if (index < shapeVector.size())
	{
		shapeVector[index]->Draw();
		if (DRAW_DELAY > 0)
			Sleep(DRAW_DELAY);

		if (ITERATION_DELAY > 0)
			Sleep(ITERATION_DELAY);
	}
}

/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: downcasting the shape pointer to derived class pointer,
//				then, pass the derived class pointer to the overloaded 
//				function 
// Inputs: Shape pointer
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void ScreenSaver::RandomAttributes(Shape *shapePtr)
{
	// declare pointers for downcasting
	MyRect *recPtr;
	MyTriangle *triPtr;
	MyCircle *cirPtr;

	// downcasting is done here
	recPtr = dynamic_cast<MyRect *>(shapePtr);
	triPtr = dynamic_cast<MyTriangle *>(shapePtr);
	cirPtr = dynamic_cast<MyCircle *>(shapePtr);

	// after downcasting, we have determined which derived object type 
	// we have and we can call that specific function on the derived class
	// through the base class pointer. Slick!!
	if (recPtr != NULL)
		RandomAttributes(*recPtr);
	if (triPtr != NULL)
		RandomAttributes(*triPtr);
	if (cirPtr != NULL)
		RandomAttributes(*cirPtr);
}



/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyRect object.
// 
// Inputs: MyRect object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void ScreenSaver::RandomAttributes(MyRect &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x = 50;
	p.y = 50;

	// define variables that will hold the parameters
	// for the rectangle
	SHAPE_COLOR firstColor = RED;
	SHAPE_COLOR lastColor = PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;
	unsigned int width;

	// reset the rectangle object to some known, legal values
	S.SetPosition(p);
	S.SetLength(S.GetWindowHeight() / 10);
	S.SetWidth(S.GetWindowWidth() / 10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % S.GetWindowHeight();
	} while (!S.SetLength(length));

	// width
	do {
		width = 1 + rand() % S.GetWindowWidth();
	} while (!S.SetWidth(width));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while (!S.SetPosition(p));
}



/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyTriangle object.
// 
// Inputs: MyTriangle object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void ScreenSaver::RandomAttributes(MyTriangle &S)
{
	// needed to draw a filled shape
	POINT p;
	p.x = 50;
	p.y = 50;

	// define variables that will hold he parameters
	// for the rectangle
	SHAPE_COLOR firstColor = RED;
	SHAPE_COLOR lastColor = PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int length;

	// reset the rectangle object to some known, legal values
	S.SetPosition(p);
	S.SetLength(S.GetWindowHeight() / 10);

	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	S.SetBorderColor((SHAPE_COLOR)myPen);
	S.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a rectangle within the legal
	// limits of the window.

	// length
	do {
		length = 1 + rand() % S.GetWindowHeight();
	} while (!S.SetLength(length));

	// position
	do {
		p.x = 1 + rand() % S.GetWindowWidth();
		p.y = 1 + rand() % S.GetWindowHeight();
	} while (!S.SetPosition(p));
}


/////////////////////////////////////////////////////////////////////
// RandomAttributes
// Description: This routine will randomy choose parameters for 
//              a MyCircle object.
// 
// Inputs: MyCircle object
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void ScreenSaver::RandomAttributes(MyCircle &circle)
{
	// needed to draw a filled shape
	POINT p;
	p.x = 50;
	p.y = 50;

	// define variables that will hold the parameters
	// for the rectangle
	SHAPE_COLOR firstColor = RED;
	SHAPE_COLOR lastColor = PURPLE;
	unsigned int myPen;
	unsigned int myBrush;
	unsigned int radius;


	// reset the rectangle object to some known, legal values
	circle.SetPosition(p);
	circle.SetRadius(circle.GetWindowHeight() / 10);


	// generate random values for our parameters, within
	// allowable limits
	myPen = (unsigned int)firstColor + rand() % (unsigned int)lastColor;

	// make sure the pen and brush colors are not the same
	do {
		myBrush = (unsigned int)firstColor + rand() % (unsigned int)lastColor;
	} while (myBrush == myPen);

	// set up the parameters of the filled shape
	// object per the random data
	circle.SetBorderColor((SHAPE_COLOR)myPen);
	circle.SetFillColor((SHAPE_COLOR)myBrush);

	// stay in each loop until you have chosen random
	// parameters which draw a radius within the legal
	// limits of the window.

	// radius
	do {
		radius = 1 + rand() % circle.GetWindowHeight();
	} while (!circle.SetRadius(radius));


	// position
	do {
		p.x = 1 + rand() % circle.GetWindowWidth();
		p.y = 1 + rand() % circle.GetWindowHeight();
	} while (!circle.SetPosition(p));
}

/////////////////////////////////////////////////////////////////////
// run
// Description: This function will excute the required functions
//              to perform.
// 
// Inputs: None
// Outputs: None
// Returns: None
/////////////////////////////////////////////////////////////////////
void ScreenSaver::run()
{
	int shapes; // loop index

	// seed the random number generator
	srand((unsigned int)time(0));

	// allow the user time to move the console window away
	// from the FilledShapes window are
	cout << "Move this window to the lower right of the screen, and press ENTER to continue:\n";
	cin.get();

	// generate the required number of random shapes
	for (int i = 0; i < NUM_SHAPES; i++)
	{

		int randomNum = rand() % 3;

		if (randomNum == 0)
			randomShape = new MyRect();
		else if (randomNum == 1)
			randomShape = new MyTriangle();
		else
			randomShape = new MyCircle();

		//polymorphism and overloading
		RandomAttributes(randomShape);

		// declare pointers for downcasting
		MyRect *recPtr;
		MyTriangle *triPtr;
		MyCircle *cirPtr;

		// downcasting is done here
		recPtr = dynamic_cast<MyRect *>(randomShape);
		triPtr = dynamic_cast<MyTriangle *>(randomShape);
		cirPtr = dynamic_cast<MyCircle *>(randomShape);

		// after downcasting, we have determined which drived object type 
		// we have and we can call that specific function on the derived class
		// through the base class pointer. Slick!!
		if (recPtr != NULL)
			shapeMap["rectangle"].push_back(randomShape);
		if (triPtr != NULL)
			shapeMap["triangle"].push_back(randomShape);
		if (cirPtr != NULL)
			shapeMap["circle"].push_back(randomShape);
	}

	// draw each shape in each vector
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		(*randomShape).ClearScreen();
		displaySingleShape(shapeMap["rectangle"], i);
		displaySingleShape(shapeMap["triangle"], i);
		displaySingleShape(shapeMap["circle"], i);
	}

}

