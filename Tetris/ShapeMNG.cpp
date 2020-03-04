#include "ShapeMNG.h"
#include "Rectangle.h"
#include "StageMNG.h"
#include "Stage.h"
ShapeMNG* ShapeMNG::instance = nullptr;

ShapeMNG::ShapeMNG() : currentshape(nullptr), nextshape(nullptr)
{
	currentshape = SetRandomShape();
	nextshape = SetRandomShape();
	shapespeed = 0;
}

ShapeMNG::~ShapeMNG()
{
	SAFE_DELETE(currentshape);
	SAFE_DELETE(nextshape);
}

void ShapeMNG::Update()
{
	Stage* stage = StageMNG::GetInstance()->GetCurrentStage();
	++shapespeed;
	if (stage->GetSpeed() == shapespeed)
	{

		if (currentshape->MoveDown())
		{
			stage->AddBlock(currentshape, currentshape->GetPosition());
			SAFE_DELETE(currentshape);

			currentshape = nextshape;
			currentshape->SetPosition(4, 0);
			nextshape = SetRandomShape();
		}
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
	currentshape->Render();
	nextshape->SetPosition(12, 4);
	nextshape->RenderNextShape();
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
