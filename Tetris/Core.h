#pragma once
#include "value.h"
class Core // ��ü���� ������ ����ϴ� �ھ�.
{
private:
	static Core* instance;
	HANDLE handle;
	bool loop;
public:
	bool Init();
	void Run();
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
	void End() { loop = false; };
};

