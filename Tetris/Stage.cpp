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
	COORD pos = { 0,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

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
				bool lineclear = true;
				// lineclear 를 true로 초기화, 근데 k번째 줄이 다 채워지지 않았다면, k번째 줄의 lineclear는 안되었다고 한 뒤 break
				for (int k = 0; k < STAGE_WIDTH; k++)
				{
					if (stage[pos.y - (3 - i)][k] != '0')
					{
						lineclear = false;
						break;
					}
				}
				if (lineclear)
				{
					for (int k = pos.y - (3 - i); k > 0; k--)
					{
						for (int l = 0; l < STAGE_WIDTH; l++)
						{
							stage[k][l] = stage[k - 1][l];
						}
					}
				}
			}
		}
	}
}

bool Stage::CheckBlock(int x, int y)
{
	// 바닥에 닿아도 리턴트루
	if (y >= STAGE_HEIGHT)
		return true;
	if (x < 0 || x >= STAGE_WIDTH)
		return true;

	return stage[y][x] == '0';
}
