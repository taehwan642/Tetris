#include "ShapeMNG.h"
#include "Rectangle.h"
#include "StageMNG.h"
#include "Stage.h"
ShapeMNG* ShapeMNG::instance = nullptr;

ShapeMNG::ShapeMNG() : currentshape(nullptr), nextshape(nullptr)
{
	currentshape = SetRandomShape();
	shapespeed = 0;
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
	Stage* stage = StageMNG::GetInstance()->GetCurrentStage();
	++shapespeed;
	if (stage->GetSpeed() == shapespeed)
	{
		currentshape->MoveDown();
		shapespeed = 0;
	}
	if (GetAsyncKeyState('A'))
		currentshape->MoveLeft();
	if (GetAsyncKeyState('D'))
		currentshape->MoveRight();
	if (GetAsyncKeyState('S'))
		currentshape->MoveDown();


}

void ShapeMNG::Render()
{
	list<Shape*>::iterator end = shapes.end();
	for (list<Shape*>::iterator iter = shapes.begin(); iter != end; iter++)
	{
		(*iter)->Render();
	}
	currentshape->Render();
}

Shape* ShapeMNG::CreateShape(SHAPE_TYPE type)
{
	Shape* shape = nullptr;

	switch (type)
	{
	case SHAPE_RECT:
		shape = new class Rectangle();
		break;
	}
	if (!shape->Init())
	{
		SAFE_DELETE(shape);
		return nullptr;
	}
	return shape;
}

Shape* ShapeMNG::SetRandomShape()
{
	int type = rand() % SHAPE_END;
	return CreateShape((SHAPE_TYPE)type);
}
