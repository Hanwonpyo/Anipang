#include "consoleController.h"
int main()
{
	MapManager::GetInstance()->makeMap();
	consoleController control;
	//반복해서수행해야함
	control.printInput();
	return 0;
}