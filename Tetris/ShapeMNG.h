#pragma once
#include "value.h"
class ShapeMNG // ��� �������� �����ϴ� Ŭ����
{
private:
	static ShapeMNG* instance;
	// ������ ��µ� ������
	class Shape* nextshape;
	// ���� �׿����� �ʰ� �����̴� ����, �� ���� �����ϴ� ����
	class Shape* currentshape;
	int shapespeed;
public:
	ShapeMNG();
	~ShapeMNG();
	void Update();
	void Render();
	class Shape* CreateShape(SHAPE_TYPE type);
	class Shape* SetRandomShape();
	static ShapeMNG* GetInstance()
	{
		if (instance == nullptr)
			instance = new ShapeMNG();
		return instance;
	}

	static void DestroyInstance()
	{
		SAFE_DELETE(instance);
	}
};

