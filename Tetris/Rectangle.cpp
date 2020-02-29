#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

bool Rectangle::Init()
{
	if (!Shape::Init())
		return false;

	shape[2][0] = '0';
	shape[2][1] = '0';
	shape[3][0] = '0';
	shape[3][1] = '0';
	widthCount = 2;
	return true;
}
