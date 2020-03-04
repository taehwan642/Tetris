#include "Shape.h"
#include "Core.h"
Shape::Shape()
{
	widthCount = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			shape[i][j] = '1';  // 1이 빈 공간 0 이 채워진거
		}
	}
}

Shape::~Shape()
{
}

bool Shape::Init()
{
	pivot.y = 3;
	pivot.x = 0;
	return true;
}

void Shape::Render()
{
	// 콘솔창에 출력할 좌표 얻어온 후 출력하기


	for (int i = 0; i < 4; ++i)
	{
		int yIndex = pos.y - (3 - i);
		if (yIndex < 0)
			continue;
		Core::GetInstance()->SetConsolePos(pos.x, yIndex);
		for (int j = 0; j < 4; ++j)
		{
			if (pos.x + j >= STAGE_WIDTH)
				continue;

			if (shape[i][j] == '0')
				cout << "□";
		}
	}
}
void Shape::RenderNextShape()
{
		for (int i = 0; i < 4; ++i)
		{
			int yIndex = pos.y - (3 - i);
			if (yIndex < 0)
				continue;
			Core::GetInstance()->SetConsolePos(pos.x, yIndex);
			for (int j = 0; j < 4; ++j)
			{
				if (shape[i][j] == '0')
					cout << "□";
				else
					cout << "  ";
			}
		}
}
// 클리핑 해줘야하는데 피봇이 문제, 가로의 양에 따라 해야함

// if 바닥에 닿음 == treu 아니면 false
bool Shape::MoveDown()
{
	if (pos.y == STAGE_HEIGHT - 1)
		return true;

	++pos.y;
	return false;
}

void Shape::MoveLeft()
{
	if (pos.x == 0)
		return;
	--pos.x;
}

void Shape::MoveRight()
{
	if (pos.x + widthCount == STAGE_WIDTH)
		return;
	++pos.x;
}
