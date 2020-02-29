#include "Core.h"
#include "StageMNG.h"
Core* Core::instance = nullptr;

bool Core::Init()
{
	// 스테이지 관리자 초기화
	if (!StageMNG::GetInstance()->Init())
		return false;

	return true;
}

void Core::Run()
{	
	StageMNG::GetInstance()->Run();
}

Core::Core()
{
}

Core::~Core()
{
	StageMNG::GetInstance()->DestroyInstance();
}

int Core::SetConsolePos(int x, int y)
{
	return 0;
}
