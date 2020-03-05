#include "Ipoly.h"

bool Ipoly::Init()
{
	if (!Shape::Init())
		return false;

	shape[0][0] = '0';
	shape[1][0] = '0';
	shape[2][0] = '0';
	shape[3][0] = '0';
	widthCount = 1;
	pos.x = 5;
	pos.y = 0;
	rotationdir = R_UP;
	return true;
}

void Ipoly::Rotate()
{
	rotationdir = rotationdir == R_DOWN ? R_UP : R_DOWN;


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
		shape[0][0] = '0';
		shape[1][0] = '0';
		shape[2][0] = '0';
		shape[3][0] = '0';
		widthCount = 1;
		break;
	case R_DOWN:
		shape[3][0] = '0';
		shape[3][1] = '0';
		shape[3][2] = '0';
		shape[3][3] = '0';
		widthCount = 4;
		break;
	}
}
