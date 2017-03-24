#include "Prey.h"

CPrey::CPrey()
{
	m_pos.X = 10;
	m_pos.Y = 10;
}

CPrey::~CPrey()
{

}

int CPrey::getX()
{
	return m_pos.X;
}

int CPrey::getY()
{
	return m_pos.Y;
}

void CPrey::drawPrey(HANDLE _myHandle, int _width, int _height)
{
	// random position of prey
	srand(time(NULL));
	m_pos.X = rand() % (_width - 1) + 1;
	m_pos.Y = rand() % (_height - 1) + 1;

	// draw prey
	SetConsoleCursorPosition(_myHandle, m_pos);
	printf("0");
}
