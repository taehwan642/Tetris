#include "Stage.h"

Stage::Stage() : speed(5)
{
}

Stage::~Stage()
{
}

bool Stage::Init()
{
	memset(stage, 0, STAGE_WIDTH * STAGE_HEIGHT);
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
				cout << "  ";
		}
		cout << endl;
	}
}
