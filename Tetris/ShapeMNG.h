#pragma once
#include "value.h"
class ShapeMNG // 모든 도형들을 관리하는 클래스
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

