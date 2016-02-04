#ifndef consoleController_H
#define consoleController_H

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#include "MapManager.h"
#include "patternChecker.h"
//#include <turboc.h>

using namespace std;

class consoleController {

private:
	int x1, y1;
	int x2, y2;
	char map;

public:
	consoleController();
	void drawScreen();
	void printInput();
	bool timeCheck(time_t start, time_t end);
	void controlMap();
	void gotoxy(int x, int y);
	void clrscr(void);
	void delay(int x);
};
#endif