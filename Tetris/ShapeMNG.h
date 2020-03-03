#pragma once
#include "value.h"
class ShapeMNG // 모든 도형들을 관리하는 클래스
{
private:
	static ShapeMNG* instance;
	// 현재 맵 쌓인! 쌓인이다! 쌓인이 중요하다! 움직이지 않고 쌓여있는 도형이다!
	list<class Shape*> shapes;
	// 다음에 출력될 도형들
	class Shape* nextshape;
	// 지금 쌓여있지 않고 움직이는 도형, 즉 내가 조종하는 도형
	class Shape* currentshape;
public:
	ShapeMNG();
	~ShapeMNG();
	void Update();
	void Render();
	class Shape* CreateShape(SHAPE_TYPE type);
	class Shape* SetRandomShape();
	static ShapeMNG* GetInstance()
	{
		if (instance == nullptr)
			instance = new ShapeMNG();
		return instance;
	}

	static void DestroyInstance()
	{
		SAFE_DELETE(instance);
	}
};

