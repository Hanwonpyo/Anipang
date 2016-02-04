#include "consoleController.h"
#include <time.h>
int main()
{ 
	time_t start, end;
	MapManager::GetInstance()->makeMap();
	consoleController control;
	start = clock() / 1000;

	while (1) {
		control.printInput();
		end = clock() / 1000;
		if (control.timeCheck(start, end))
			break;
	}
	return 0;
}