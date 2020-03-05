#include "Tpoly.h"

bool Tpoly::Init()
{
	if (!Shape::Init())
		return false;

	shape[2][0] = '0';
	shape[2][1] = '0';
	shape[2][2] = '0';
	shape[3][1] = '0';
	widthCount = 3;
	pos.x = 5;
	pos.y = 0;
	rotationdir = R_DOWN;
	return true;
}

void Tpoly::Rotate()
{
	rotationdir++;
	// %= 하는 이유는 만약 ++되었을때 4가 된다면 다시 0으로 되돌아가게 하기 위해서. 0이면 다시 UP이 되니까 초기화 목적
	rotationdir %= R_END;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = '1';
		}
	}

	switch (rotationdir)
	{
	case R_UP:
		shape[2][1] = '0';
		shape[3][0] = '0';
		shape[3][1] = '0';
		shape[3][2] = '0';
		widthCount = 3;
		break;
	case R_RIGHT:
		shape[1][0] = '0';
		shape[2][0] = '0';
		shape[2][1] = '0';
		shape[3][0] = '0';
		widthCount = 2;
		break;
	case R_DOWN:
		shape[2][0] = '0';
		shape[2][1] = '0';
		shape[2][2] = '0';
		shape[3][1] = '0';
		widthCount = 3;
		break;
	case R_LEFT:
		shape[1][1] = '0';
		shape[2][0] = '0';
		shape[2][1] = '0';
		shape[3][1] = '0';
		widthCount = 2;
		break;
	}
}
