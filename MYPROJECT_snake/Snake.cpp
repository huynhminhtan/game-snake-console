
#include "Snake.h"

// define class CNodeSnake
CSnake::CNodeSnake::CNodeSnake()
{
	m_x = 5;
	m_y = 5;

	m_pNext = nullptr;
}

CSnake::CNodeSnake::CNodeSnake(int _x, int _y)
{
	m_x = _x;
	m_y = _y;

	m_pNext = nullptr;
}


CSnake::CNodeSnake::~CNodeSnake()
{
	delete m_pNext;
}

COORD CSnake::CNodeSnake::getCoordNodeSnake()
{
	COORD temp;

	temp.X = m_x;
	temp.Y = m_y;

	return temp;
}

CSnake::CNodeSnake* CSnake::CNodeSnake::getpNext()
{
	return m_pNext;
}

void CSnake::CNodeSnake::setpNext(CNodeSnake* _node)
{
	m_pNext = _node;
}

void CSnake::CNodeSnake::setCoordNodeSnake(COORD _coord)
{
	m_x = _coord.X;
	m_y = _coord.Y;
}

int CSnake::CNodeSnake::getX()
{
	return m_x;
}

int CSnake::CNodeSnake::getY()
{
	return m_y;
}

// define class CSnake
CSnake::CSnake()
{
	m_speedX = 1;
	m_speedY = 0;

	CNodeSnake* node = new CNodeSnake;

	m_headSnake = node;
}

CSnake::CSnake(CNodeSnake* _phead)
{
	m_speedX = 1;
	m_speedY = 0;

	m_headSnake = _phead;
}

//CSnake::~CSnake()
//{
//	delete m_headSnake;
//}

void CSnake::addNodeSnakeTail()
{
	

	CNodeSnake* p = CSnake::m_headSnake;

	while (p->getpNext() != nullptr)
	{
		p = p->getpNext();
	}

	CNodeSnake* node = new CNodeSnake(p->getX() - 1, p->getY());

	if (node == nullptr)
	{
		printf("err! Don't new node\n");
		exit(0);
	}

	p->setpNext(node);
	
}

void CSnake::drawSnake(HANDLE _myHandle)
{
	CNodeSnake* p = m_headSnake;
	COORD coord;

	while (p != nullptr)
	{
		coord = p->getCoordNodeSnake();

		SetConsoleCursorPosition(_myHandle, coord);
		printf("X");

		p = p->getpNext();
	}
}

CSnake::CNodeSnake* CSnake::getHeadSnake()
{
	return m_headSnake;
}

void CSnake::input(HANDLE _myHandle)
{
	// input key
	//COORD coord;
	//coord = m_headSnake->getCoordNodeSnake();
	m_posHeadSnack = m_headSnake->getCoordNodeSnake();

	if (GetAsyncKeyState(VK_LEFT))
	{
		m_speedX = -1;
		m_speedY = 0;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_speedX = 1;
		m_speedY = 0;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_speedY = -1;
		m_speedX = 0;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_speedY = 1;
		m_speedX = 0;
	}

	
	/*coord.X += m_speedX;
	coord.Y += m_speedY;*/

	 m_posHeadSnack.X += m_speedX;
	 m_posHeadSnack.Y += m_speedY;

	//m_headSnake->setCoordNodeSnake(coord);
}

void CSnake::crawling(HANDLE _myHandle)
{
	// tim node ke cuoi va node cuoi
	CSnake::CNodeSnake* nodeTail = m_headSnake;
	CSnake::CNodeSnake* nodeAdjacentTail = m_headSnake;

	while (nodeTail->getpNext() != nullptr)
	{
		nodeAdjacentTail = nodeTail;
		nodeTail = nodeTail->getpNext();
	}

	// noi node dau va node cuoi
	nodeTail->setpNext(m_headSnake);
	nodeAdjacentTail->setpNext(nullptr);
	m_headSnake = nodeTail;


	// xoa node cuoi tren console
	SetConsoleCursorPosition(_myHandle, nodeTail->getCoordNodeSnake());
	printf(" ");

	// cap nhat lai vi tri cua cursor
	m_headSnake->setCoordNodeSnake(m_posHeadSnack);
}

void CSnake::eatPrey()
{
	
}