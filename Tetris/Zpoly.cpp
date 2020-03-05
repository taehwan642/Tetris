#include "Zpoly.h"

bool Zpoly::Init()
{
	if (!Shape::Init())
		return false;

	shape[2][0] = '0';
	shape[2][1] = '0';
	shape[3][1] = '0';
	shape[3][2] = '0';
	widthCount = 2;
	pos.x = 5;
	pos.y = 0;
	rotationdir = R_LEFT;
	return true;
}

void Zpoly::Rotate()
{
	rotationdir = rotationdir == R_LEFT ? R_DOWN : R_LEFT;


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = '1';
		}
	}


	switch (rotationdir)
	{
	case R_LEFT:
		shape[2][0] = '0';
		shape[2][1] = '0';
		shape[3][1] = '0';
		shape[3][2] = '0';
		widthCount = 3;
		break;
	case R_DOWN:
		shape[1][1] = '0';
		shape[2][0] = '0';
		shape[2][1] = '0';
		shape[3][0] = '0';
		widthCount = 2;
		break;
	}
}
