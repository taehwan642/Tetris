#pragma once
#include "Shape.h"
class Opoly : public Shape // 2 X 2 ����
{
public:
	Opoly();
	~Opoly();
	bool Init() override;
	void Rotate() override {};
	// Opoly�� rotate�� �ص� ���� ���⿡ �׳� ����X
};

