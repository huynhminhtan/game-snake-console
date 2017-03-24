#pragma once

#include <Windows.h>
#include <stdio.h>
#include "Snake.h"
#include "Prey.h"

class CGame
{
private:
	int m_width;
	int m_height;
	HANDLE myconsoleHandle;

	void drawWindows();
public:
	CGame();
	CGame(int, int);
	~CGame();

	void gameLoop();
	void eatPrey(CSnake&, CPrey&);
	void gameExit(CSnake&);
};