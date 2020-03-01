#include "Core.h"
#include "StageMNG.h"
Core* Core::instance = nullptr;

bool Core::Init()
{
	// 콘솔 핸들 추가
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (handle == INVALID_HANDLE_VALUE)
		return false;

	// 스테이지 관리자 초기화
	if (!StageMNG::GetInstance()->Init())
		return false;

	return true;
}

void Core::Run()
{	
	StageMNG::GetInstance()->Run();
	// 가로 2입니다 이게 하나당 2바이트죠?(■) 2칸짜리란 얘깁니다. 영문기준으로 나와요? 2칸을갔는데 그러면 우리는 1칸간거나 마찬가지지.
}

Core::Core()
{
}

Core::~Core()
{
	StageMNG::GetInstance()->DestroyInstance();
}

void Core::SetConsolePos(int x, int y)
{
	// x 에 2를 곱해주는 이유는 ■가 2칸을 차지해서, 좌표를 조정해야함 즉 1이 매개변수에 들어간다면 정확히는 2번째에 넣어지는거임.
	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(handle, pos);
}
