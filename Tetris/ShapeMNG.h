#pragma once
#include "value.h"
class ShapeMNG // ��� �������� �����ϴ� Ŭ����
{
private:
	static ShapeMNG* instance;
	// ���� �� ����! �����̴�! ������ �߿��ϴ�! �������� �ʰ� �׿��ִ� �����̴�!
	list<class Shape*> shapes;
	// ������ ��µ� ������
	class Shape* nextshape;
	// ���� �׿����� �ʰ� �����̴� ����, �� ���� �����ϴ� ����
	class Shape* currentshape;
public:
	ShapeMNG();
	~ShapeMNG();
	void Update();
	class Shape* createshape;
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

