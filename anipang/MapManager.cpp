#include "MapManager.h"
#include "makeRandomShape.h"

MapManager::MapManager()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			makeRandomShape random;
			map[i][j] = random.getShape();
			
		}
	}
}
MapManager* MapManager::GetInstance()
{
	return mapManager;
}
void MapManager::FreeInstance()
{
	if (mapManager){
		delete mapManager;
		mapManager = NULL;
	}
}
void MapManager::fillMap(int x, int y)
{
	makeRandomShape random;
	map[x][y] = random.getShape();
}
void MapManager::deleteBlock(int x, int y)
{
	map[x][y] = ' ';
}
void MapManager::swapBlock(int x1, int y1, int x2, int y2)
{
	char temp;
	temp = map[x1][y1];
	map[x1][y1] = map[x2][y2];
	map[x2][y2] = temp;
}
char MapManager::getmapValue(int x, int y)
{
	return map[x][y];
}
