///////////////////////////////////////////////////////////////////////////////
// Wei Liu
// CIS 554 HW 9
// MyCircle
//
// Description: Implementation of class MyCircle. See MyCircle.h for details
//
///////////////////////////////////////////////////////////////////////////////
#include "MyCircle.h"

using std::cout;
using std::cin;
using std::endl;

///////////////////////////////////////////////////////////////////////////////
// Mycircledefault constructor
///////////////////////////////////////////////////////////////////////////////
// initialize default circle attributes
MyCircle::MyCircle() : radius(WINDOW_MAXY / 4){}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::Draw()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::Draw()
{
	// set up attributes of circle using FilledShapes
	fs.SetPenColor(borderColor);
	fs.SetBrushColor(fillColor);

	// draw circle with set attributes
	// when drawing, take into account the border width by subtracting the border
	// width appropriately from the radius. that way, the given radius 
	// include the width of the border
	fs.FilledCircle(position, radius - 2 * borderWidth);
	return true;
}

///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetRadius()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetRadius(unsigned int radius)
{
	// need to account for a min radius based
	// upon the border width
	if (radius <= 2 * borderWidth) return false;

	 //check to make sure the new radius is valid based on current position
	 //and window height
	if (position.y < GetWindowHeight() - radius && position.y > radius
		&& position.x < GetWindowWidth() - radius && position.x > radius)
	{
		this->radius = radius;
		return true;
	}
	//if (radius < GetWindowHeight() / 2 && radius < GetWindowWidth() / 2)
	//	return true;
	return false;
}


///////////////////////////////////////////////////////////////////////////////
// MyCircle::SetPosition()
///////////////////////////////////////////////////////////////////////////////
bool MyCircle::SetPosition(POINT & p)
{
	// make sure new position is valid based on current radius
	if (p.y < GetWindowHeight() - radius && p.y > radius
		&& p.x < GetWindowWidth() - radius && p.x > radius)
	{
		position.x = p.x;
		position.y = p.y;
		return true;
	}
	return false;
}


///////////////////////////////////////////////////////////////////////////////
// MyCircle::GetRadius()
///////////////////////////////////////////////////////////////////////////////
unsigned int MyCircle::GetRadius()
{
	return radius;
}
