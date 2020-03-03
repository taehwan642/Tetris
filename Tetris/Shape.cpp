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
		Core::GetInstance()->SetConsolePos(pos.x, pos.y - (3 - i));
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
void Shape::MoveDown()
{
	if (pos.y == STAGE_HEIGHT - 1)
		return;

	++pos.y;
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
