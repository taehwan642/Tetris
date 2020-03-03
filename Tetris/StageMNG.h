#pragma once

#include "value.h"

class StageMNG // 스테이지를 관리하는 클래스
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

