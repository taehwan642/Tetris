#pragma once

#include "value.h"

class StageMNG
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

