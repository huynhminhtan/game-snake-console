#pragma once

#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <stdio.h>

class CPrey
{
	COORD m_pos;

public:
	CPrey();
	~CPrey();

	int getX();
	int getY();
	void drawPrey(HANDLE _myHandle, int _width, int _height);
};