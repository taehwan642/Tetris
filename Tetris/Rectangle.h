#pragma once
#include "Shape.h"
class Rectangle : // 2 X 2 ����
	public Shape
{
public:
	Rectangle();
	~Rectangle();
	bool Init() override;
};

