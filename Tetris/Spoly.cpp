#include "Spoly.h"

bool Spoly::Init()
{
	if (!Shape::Init())
		return false;

	shape[2][1] = '0';
	shape[2][2] = '0';
	shape[3][0] = '0';
	shape[3][1] = '0';
	widthCount = 2;
	pos.x = 5;
	pos.y = 0;
	rotationdir = R_RIGHT;
	return true;
}

void Spoly::Rotate()
{
	rotationdir = rotationdir == R_RIGHT ? R_DOWN : R_RIGHT;


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape[i][j] = '1';
		}
	}


	switch (rotationdir)
	{
	case R_RIGHT:
		shape[2][1] = '0';
		shape[2][2] = '0';
		shape[3][0] = '0';
		shape[3][1] = '0';
		widthCount = 3;
		break;
	case R_DOWN:
		shape[1][0] = '0';
		shape[2][0] = '0';
		shape[2][1] = '0';
		shape[3][1] = '0';
		widthCount = 2;
		break;
	}
}
