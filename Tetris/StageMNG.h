#pragma once

#include "value.h"

class StageMNG // ���������� �����ϴ� Ŭ����
{
private:
	static StageMNG* instance;
	class Stage* currentstage;
public:
	bool Init();
	void Run();
public:
	StageMNG();
	~StageMNG();
	class Stage* GetCurrentStage() { return currentstage; };
	static StageMNG* GetInstance()
	{
		if (instance == nullptr)
			instance = new StageMNG;
		return instance;
	}
	static void DestroyInstance()
	{
		SAFE_DELETE(instance);
	}
};

