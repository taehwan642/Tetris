#pragma once
#include "Shape.h"
class Rectangle : // 2 X 2 µµÇü
	public Shape
{
public:
	Rectangle();
	~Rectangle();
	bool Init() override;
};

