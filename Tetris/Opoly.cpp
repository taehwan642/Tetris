#include "Opoly.h"

Opoly::Opoly()
{
}

Opoly::~Opoly()
{
}

bool Opoly::Init()
{
	if (!Shape::Init())
		return false;

	shape[2][0] = '0';
	shape[2][1] = '0';
	shape[3][0] = '0';
	shape[3][1] = '0';
	widthCount = 2;
	pos.x = 5;
	pos.y = 0;

	return true;
}
