#pragma once
#include "value.h"
class Shape // ��� ��Ʈ�ι̳�, �� �������� �⺻ Ŭ����
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
	void RenderNextShape();
	bool MoveDown();
	void MoveLeft();
	void MoveRight();

	char GetBlock(int x, int y) const
	{
		return shape[y][x];
	}
	
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

