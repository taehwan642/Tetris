#include "Stage.h"
#include "Core.h"
#include "Shape.h"
Stage::Stage() : speed(5)
{
}

Stage::~Stage()
{
}

bool Stage::Init()
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			stage[i][j] = '1';
		}
	}
	return true;
}

void Stage::Render()
{
	for (int i = 0; i < STAGE_HEIGHT + 1; ++i) // 왜 선처리? 나중에 망가트려보자 i++로
	{
		for (int j = 0; j < STAGE_WIDTH + 2; ++j)
		{
			if (i == 0 && (j == 0 || j == STAGE_WIDTH + 1))
				cout << "■";
			else if (j == 0)
				cout << "■";
			else if (i == STAGE_HEIGHT)
				cout << "■";
			else if (j == STAGE_WIDTH + 1)
				cout << "■";
			else
			{
				if (stage[i][j - 1] == '1')
					cout << "  ";
				else
					cout << "□";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 7; ++i)
	{
		Core::GetInstance()->SetConsolePos(17, i);
		cout << "■";
	}
	for (int i = 0; i < 6; ++i)
	{
		Core::GetInstance()->SetConsolePos(11 + i, 6);
		cout << "■";
	}
}

void Stage::AddBlock(Shape* s, const POSITION& pos)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s->GetBlock(j, i) == '0')
			{
				stage[pos.y - (3 - i)][pos.x + j] = '0';
			}
		}
	}
}
