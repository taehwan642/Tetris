#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <list>
using namespace std;

#include "Macro.h"
#include "Flags.h"

#define STAGE_WIDTH 10 // 스테이지의 가로
#define STAGE_HEIGHT 15 // 스테이지의 세로

typedef struct tagPosition // 도형의 위치값을 만들어줌. Vector2라고 생각하면 편함
{
	int x;
	int y;
	tagPosition() : x(0), y(0)
	{

	}

	tagPosition(const tagPosition& pos)
	{
		*this = pos;
	}

	tagPosition(int _x, int _y) : x(_x), y(_y)
	{

	}

	tagPosition operator+(const tagPosition& p)
	{
		tagPosition position;
		position.x = x + p.x;
		position.y = y + p.y;
		return position;
	}

	tagPosition operator+(int val)
	{
		tagPosition position;
		position.x = x + val;
		position.y = y + val;
		return position;
	}

	void operator+=(const tagPosition& p)
	{
		x += p.x;
		y += p.y;
	}

	void operator+=(int val)
	{
		x += val;
		y += val;
	}

	tagPosition operator-(const tagPosition& p)
	{
		tagPosition position;
		position.x = x - p.x;
		position.y = y - p.y;
		return position;
	}

	tagPosition operator-(int val)
	{
		tagPosition position;
		position.x = x - val;
		position.y = y - val;
		return position;
	}

	void operator-=(const tagPosition& p)
	{
		x -= p.x;
		y -= p.y;
	}

	void operator-=(int val)
	{
		x -= val;
		y -= val;
	}

	void operator= (const tagPosition& p)
	{
		x = p.x;
		y = p.y;
	}

}POSITION,*_POSITION;