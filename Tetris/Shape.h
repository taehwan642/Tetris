#pragma once
#include "value.h"
class Shape
{
protected:
	char shape[4][4];
	POSITION pos;
	POSITION pivot;
	int widthCount;
public:
	Shape();
	virtual ~Shape();
	virtual bool Init();
	void Render();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	//�������� ���� �� �����ٰ� �� ���
	void SetPosition(int x, int y)
	{
		pos.x = x;
		pos.y = y;
	}

	void SetPosition(const POSITION& p)
	{
		pos = p;
	}

	POSITION GetPosition() const
	{
		return pos;
	}

	POSITION GetPivot() const
	{
		return pivot;
	}
};

