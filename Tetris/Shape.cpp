#include "Shape.h"
#include "Core.h"
#include "Stage.h"
#include "StageMNG.h"
Shape::Shape()
{
	rotationdir = R_UP;
	widthCount = 0;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			shape[i][j] = '1';  // 1�� �� ���� 0 �� ä������
		}
	}
}

Shape::~Shape()
{
}

bool Shape::Init()
{
	pivot.y = 3;
	pivot.x = 0;
	return true;
}

void Shape::Render()
{
	// �ܼ�â�� ����� ��ǥ ���� �� ����ϱ�


	for (int i = 0; i < 4; ++i)
	{
		int yIndex = pos.y - (3 - i);
		if (yIndex < 0)
			continue;
		for (int j = 0; j < 4; ++j)
		{
			if (pos.x + j >= STAGE_WIDTH)
				continue;

			if (shape[i][j] == '0')
			{
				Core::GetInstance()->SetConsolePos(pos.x + j, yIndex);
				cout << "��";
			}
			// ������� ���ϸ� �׸� ������ �ϴµ�, ���� �̻��ϰ� �����ܼ� ����. ��������� �ʿ���. ������ pos.x + j�� �߱� ������ ������¾��ص���
		}
	}
}
void Shape::RenderNextShape()
{
		for (int i = 0; i < 4; ++i)
		{
			int yIndex = pos.y - (3 - i);
			if (yIndex < 0)
				continue;
			for (int j = 0; j < 4; ++j)
			{
				if (shape[i][j] == '0')
				{
					Core::GetInstance()->SetConsolePos(pos.x + j, yIndex);
					cout << "��";
				}
				
			}
		}
}
// Ŭ���� ������ϴµ� �Ǻ��� ����, ������ �翡 ���� �ؾ���

// if �ٴڿ� ���� == treu �ƴϸ� false
bool Shape::MoveDown()
{
	Stage* stage = StageMNG::GetInstance()->GetCurrentStage(); 
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shape[i][j] == '0')
			{
				if (stage->CheckBlock(pos.x + j, pos.y - (2 - i)))
				{
					for (int k = 0; k < 4; k++)
					{
						for (int l = 0; l < 4; l++)
						{
							if (shape[k][l] == '0')
							{
								if (pos.y - (3 - k) < 0)
								{
									Core::GetInstance()->End();
									break;
								}
							}
						}
					}
					return true;
				}
			}
		}
	}
	++pos.y;
	return false;
}

void Shape::MoveLeft()
{
	if (pos.x == 0)
		return;

	Stage* stage = StageMNG::GetInstance()->GetCurrentStage();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shape[i][j] == '0')
			{
				if (stage->CheckBlock(pos.x + j - 1, pos.y - (3 - i)))
				{
					return;
				}
			}
		}
	}

	--pos.x;
}

void Shape::MoveRight()
{
	if (pos.x + widthCount == STAGE_WIDTH)
		return;

	Stage* stage = StageMNG::GetInstance()->GetCurrentStage();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (shape[i][j] == '0')
			{
				if (stage->CheckBlock(pos.x + j + 1, pos.y - (3 - i)))
				{
					return;
				}
			}
		}
	}
	++pos.x;
}
