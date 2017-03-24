#include "Game.h"

CGame::CGame()
{
	m_height = 20;
	m_width = 70;
	
	// init handle
	myconsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// hide cursor
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(myconsoleHandle, &info);
	
	// draw windows
	this->drawWindows();
}

CGame::CGame(int _width, int _height)
{
	m_width = _width;
	m_height = _height;

	// init handle
	myconsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// hide cursor
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(myconsoleHandle, &info);

	// draw windows
	this->drawWindows();
}

CGame::~CGame()
{
	
}

void CGame::drawWindows()
{
	COORD temp;

	// draw horizontal
	for (int i = 0; i < m_width + 1; i++)
	{
		temp.X = i;
		temp.Y = m_height;
		SetConsoleCursorPosition(myconsoleHandle, temp);
		printf("0");
	}

	// draw vertical
	for (int i = 0; i < m_height +1; i++)
	{
		temp.X = m_width;
		temp.Y = i;
		SetConsoleCursorPosition(myconsoleHandle, temp);
		printf("0");
	}
}

void CGame::gameLoop()
{
	CPrey prey;
	CSnake mySnake;

	// draw prey
	prey.drawPrey(myconsoleHandle, m_width, m_height);

	while (true)
	{
		mySnake.input(myconsoleHandle);
		mySnake.crawling(myconsoleHandle);
		mySnake.drawSnake(myconsoleHandle);
		this->eatPrey(mySnake, prey);
		this->gameExit(mySnake);

		Sleep(100);
	}

}

void CGame::eatPrey(CSnake& _snake, CPrey& _prey)
{
	if (_snake.getHeadSnake()->getX() == _prey.getX() &&
		_snake.getHeadSnake()->getY() == _prey.getY())
	{
		// add node snack
		_snake.addNodeSnakeTail();

		// draw prey
		_prey.drawPrey(myconsoleHandle, m_width, m_height);
	}
}

void CGame::gameExit(CSnake& _snake)
{
	// dung windows
	if (_snake.getHeadSnake()->getX() == m_width ||
		_snake.getHeadSnake()->getY() == m_height ||
		_snake.getHeadSnake()->getX() == 0 ||
		_snake.getHeadSnake()->getY() == 0)
	{
		MessageBox(
			NULL,
			"GAME oVeR !!!",
			"THUA ROI",
			NULL
			);

		exit(0);
	}

	// dung duoi
	CSnake::CNodeSnake* p = _snake.getHeadSnake()->getpNext();

	while (p != nullptr)
	{
		if (_snake.getHeadSnake()->getX() == p->getX() &&
			_snake.getHeadSnake()->getY() == p->getY())
		{
			MessageBox(
				NULL,
				"game over!",
				"thua roi",
				NULL
				);

			exit(0);
		}
		p = p->getpNext();
	}
}
