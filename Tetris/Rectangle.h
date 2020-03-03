#pragma once
#include "Shape.h"
class Rectangle : public Shape // 2 X 2 µµÇü
{
public:
	Rectangle();
	~Rectangle();
	bool Init() override;
};

