#pragma once
#include "Shape.h"
class Opoly : public Shape // 2 X 2 도형
{
public:
	Opoly();
	~Opoly();
	bool Init() override;
	void Rotate() override {};
	// Opoly는 rotate를 해도 뭣도 없기에 그냥 구현X
};

