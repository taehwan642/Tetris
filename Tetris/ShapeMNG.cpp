#include "ShapeMNG.h"
#include "Opoly.h"
#include "Ipoly.h"
#include "Jpoly.h"
#include "Lpoly.h"
#include "Spoly.h"
#include "Zpoly.h"
#include "Tpoly.h"
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
	if (GetAsyncKeyState('W') & 0x8000)
		currentshape->Rotate();
	if (GetAsyncKeyState('A') & 0x8000)
		currentshape->MoveLeft();
	if (GetAsyncKeyState('D') & 0x8000)
		currentshape->MoveRight();
	if (GetAsyncKeyState('S') & 0x8000)
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
	case SHAPE_O:
		shape = new  Opoly();
		break;
	case SHAPE_I:
		shape = new Ipoly();
		break;
	case SHAPE_J:
		shape = new Jpoly();
		break;
	case SHAPE_L:
		shape = new Lpoly();
		break;
	case SHAPE_S:
		shape = new Spoly();
		break;
	case SHAPE_Z:
		shape = new Zpoly();
		break;
	case SHAPE_T:
		shape = new Tpoly();
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
