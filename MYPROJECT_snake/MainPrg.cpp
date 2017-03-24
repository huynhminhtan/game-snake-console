
#include "MainPrg.h"

int main()
{

	CGame myGameSnake(70, 20);
	
	myGameSnake.gameLoop();

	while (1);
	return 0;

}