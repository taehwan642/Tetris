#include "Shape.h"
#include "Core.h"
#include "Stage.h"
#include "StageMNG.h"
Shape::Shape()
{
	rotationdir = R_UP;
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
		for (int j = 0; j < 4; ++j)
		{
			if (pos.x + j >= STAGE_WIDTH)
				continue;

			if (shape[i][j] == '0')
			{
				Core::GetInstance()->SetConsolePos(pos.x + j, yIndex);
				cout << "□";
			}
			// 공백출력 안하면 네모가 나오긴 하는데, 존내 이상하게 끌어당겨서 나옴. 공백출력이 필요함. 하지만 pos.x + j를 했기 때문에 공백출력안해도됨
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
			for (int j = 0; j < 4; ++j)
			{
				if (shape[i][j] == '0')
				{
					Core::GetInstance()->SetConsolePos(pos.x + j, yIndex);
					cout << "□";
				}
				
			}
		}
}
// 클리핑 해줘야하는데 피봇이 문제, 가로의 양에 따라 해야함

// if 바닥에 닿음 == treu 아니면 false
bool Shape::MoveDown()
{
	Stage* stage = StageMNG::GetInstance()->GetCurrentStage(); 
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shape[i][j] == '0')
			{
				if (stage->CheckBlock(pos.x + j, pos.y - (2 - i)))
				{
					for (int k = 0; k < 4; k++)
					{
						for (int l = 0; l < 4; l++)
						{
							if (shape[k][l] == '0')
							{
								if (pos.y - (3 - k) < 0)
								{
									Core::GetInstance()->End();
									break;
								}
							}
						}
					}
					return true;
				}
			}
		}
	}
	++pos.y;
	return false;
}

void Shape::MoveLeft()
{
	if (pos.x == 0)
		return;

	Stage* stage = StageMNG::GetInstance()->GetCurrentStage();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shape[i][j] == '0')
			{
				if (stage->CheckBlock(pos.x + j - 1, pos.y - (3 - i)))
				{
					return;
				}
			}
		}
	}

	--pos.x;
}

void Shape::MoveRight()
{
	if (pos.x + widthCount == STAGE_WIDTH)
		return;

	Stage* stage = StageMNG::GetInstance()->GetCurrentStage();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shape[i][j] == '0')
			{
				if (stage->CheckBlock(pos.x + j + 1, pos.y - (3 - i)))
				{
					return;
				}
			}
		}
	}
	++pos.x;
}
