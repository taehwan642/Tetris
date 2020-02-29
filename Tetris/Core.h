#pragma once
#include "value.h"
class Core
{
private:
	static Core* instance;
	HANDLE handle;
public:
	bool Init();
	void Run();

public:
	Core();
	~Core();
	static Core* GetInstance()
	{
		if (instance == nullptr)
			instance = new Core();
		return instance;
	}
	static void DestroyInstance()
	{
		SAFE_DELETE(instance);
	}
	int SetConsolePos(int x, int y);
};

