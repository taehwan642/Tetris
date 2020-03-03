#include "Core.h"
#include "StageMNG.h"
#include "ShapeMNG.h"
Core* Core::instance = nullptr;

bool Core::Init()
{
	// �ܼ� �ڵ� �߰�
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (handle == INVALID_HANDLE_VALUE)
		return false;

	// �������� ������ �ʱ�ȭ
	if (!StageMNG::GetInstance()->Init())
		return false;
	
	return true;
}

void Core::Run()
{	
	while (true)
	{
		system("cls");
		ShapeMNG::GetInstance()->Update();
		StageMNG::GetInstance()->Run();
		ShapeMNG::GetInstance()->Render();
		Sleep(100);
	}
	// ���� 2�Դϴ� �̰� �ϳ��� 2����Ʈ��?(��) 2ĭ¥���� ���ϴ�. ������������ ���Ϳ�? 2ĭ�����µ� �׷��� �츮�� 1ĭ���ų� ����������.
}

Core::Core()
{
	srand(time(0));
}

Core::~Core()
{
	ShapeMNG::GetInstance()->DestroyInstance();
	StageMNG::GetInstance()->DestroyInstance();
}

void Core::SetConsolePos(int x, int y)
{
	// x �� 2�� �����ִ� ������ �ᰡ 2ĭ�� �����ؼ�, ��ǥ�� �����ؾ��� �� 1�� �Ű������� ���ٸ� ��Ȯ���� 2��°�� �־����°���.
	COORD pos = { (x + 1) * 2,y };
	SetConsoleCursorPosition(handle, pos);
}
