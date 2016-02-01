
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#pragma warning(disable:4996)

class MapManager {

private:
	char map[10][10];
	static MapManager *mapManager;
public:
	MapManager(void);
	MapManager* GetInstance();
	void FreeInstance();
	void deleteBlock(int x, int y);
	void swapBlock(int x1, int y1, int x2, int y2);
	void fillMap(int x, int y);
	char getmapValue(int x, int y);
	char getMap();
	
};
MapManager* MapManager::mapManager = 0;