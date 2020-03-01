#include "Core.h"

int main(void) 
{
	if (!Core::GetInstance()->Init())
	{
		Core::GetInstance()->DestroyInstance();
		return 0;
	}

	Core::GetInstance()->Run();
	Core::GetInstance()->DestroyInstance();

	return 0;
}