#include "consoleController.h"

consoleController::consoleController()
{

}
void consoleController::drawScreen()
{
	//map °»½Å
	MapManager::GetInstance()->printMap();
	this->delay(1500);
	clrscr();
	while (MapManager::GetInstance()->hasEmptyBlock()) {
		MapManager::GetInstance()->shiftBlock();
		MapManager::GetInstance()->printMap();
		this->delay(1500);
		clrscr();
	}
}
void consoleController::printInput()
{
	MapManager::GetInstance()->printMap();
	gotoxy(10, 0);
	cout << endl;
	cout << "Enter coordinate(x1,y1,x2,y2) : ";
	cin >> x1 >> y1 >> x2 >> y2;
	Block a(x1, y1, MapManager::GetInstance()->getmapValue(x1,y1));
	Block b(x2, y2, MapManager::GetInstance()->getmapValue(x2,y2));
	clrscr();
	if (a.isnearBlock(b))
		this->controlMap();
	else
		cout << "Input Error" << endl;

}
void consoleController::controlMap()
{
	MapManager::GetInstance()->swapBlock(x1, y1, x2, y2);
	MapManager::GetInstance()->printMap();
	delay(1500);
	clrscr();

	while (1) {
		patternChecker p;
		if (p.checkPang(x1,y1,MapManager::GetInstance()->getmapValue(x1,y1)) || 
			p.checkPang(x2,y2,MapManager::GetInstance()->getmapValue(x2,y2))) {

			MapManager::GetInstance()->deleteBlock(p.getVector());
			this->drawScreen();
		}
		else {
			break;
		}
	}
}
void consoleController::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void consoleController::clrscr(void)
{
	system("cls");
}
void consoleController::delay(int x)
{
	Sleep(x);
}