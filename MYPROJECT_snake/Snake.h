#pragma once

#include <Windows.h>
#include <stdio.h>

class CSnake
{
public:
	class CNodeSnake
	{
	private:
		int m_x;
		int m_y;
		CNodeSnake* m_pNext;

	public:
		CNodeSnake();
		CNodeSnake(int, int);
		~CNodeSnake();
		
		COORD getCoordNodeSnake();
		int getX();
		int getY();
		void setCoordNodeSnake(COORD);
		CNodeSnake* getpNext();
		void setpNext( CNodeSnake*);
	};

	CSnake();
	CSnake(CNodeSnake*);
	//~CSnake();

	CNodeSnake* getHeadSnake();
	void addNodeSnakeTail();
	void drawSnake(HANDLE _myHandle);
	void input(HANDLE _myHandle);
	void crawling(HANDLE _myHandle);
	void eatPrey();

private:
	CNodeSnake* m_headSnake;
	int m_speedX;
	int m_speedY;
	COORD m_posHeadSnack;
};