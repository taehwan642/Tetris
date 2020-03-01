#pragma once
#include "value.h"
class Core // ��ü���� ������ ����ϴ� �ھ�.
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
	void SetConsolePos(int x, int y);
};

