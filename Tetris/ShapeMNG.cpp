#include "ShapeMNG.h"
#include "Rectangle.h"

ShapeMNG* ShapeMNG::instance = nullptr;

ShapeMNG::ShapeMNG() : currentshape(nullptr), nextshape(nullptr)
{
	
}

ShapeMNG::~ShapeMNG()
{
	list<Shape*>::iterator end = shapes.end();
	for (list<Shape*>::iterator iter = shapes.begin(); iter != end; iter++)
	{
		SAFE_DELETE(*iter);
	}
	SAFE_DELETE(currentshape);
	SAFE_DELETE(nextshape);
	// ������ �̰ŷε� �����غ���
	//for (auto it : shapes)
	//{
	//	delete it;
	//}
	//shapes.clear();
}

void ShapeMNG::Update()
{
}
