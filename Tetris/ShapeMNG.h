#pragma once
#include "value.h"
class ShapeMNG // ��� �������� �����ϴ� Ŭ����
{
private:
	static ShapeMNG* instance;
public:
	ShapeMNG();
	~ShapeMNG();
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

