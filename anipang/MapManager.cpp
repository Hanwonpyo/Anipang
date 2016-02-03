#include "MapManager.h"

MapManager* MapManager::mapManager;
MapManager::MapManager()
{

}
MapManager* MapManager::GetInstance()
{
	if (mapManager == NULL)
		mapManager = new MapManager();
	return mapManager;
}
void MapManager::FreeInstance()
{
	if (mapManager){
		delete mapManager;
		mapManager = NULL;
	}
}
void MapManager::makeMap()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			makeRandomShape random;
			map[i][j] = random.getShape();
			patternChecker p;
			while (p.checkPang(i, j, map[i][j])) {
				makeRandomShape random;
				map[i][j] = random.getShape();
			}
		}
	}
}
void MapManager::fillMap(int x, int y)
{
	makeRandomShape random;
	map[x][y] = random.getShape();
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
void MapManager::printMap()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j];
		}cout << "\n";
	}
}
void MapManager::deleteBlock(vector<Block> vec_delete)
{
	for (int i = 0; i < vec_delete.size(); i++) {
		map[vec_delete[i].getX()][vec_delete[i].getY()] = ' ';
	}
}
void MapManager::shiftBlock()
{
	int i, j;
	for (i = 9; i >=0 ; i--) {
		for (j = 0; j < 10; j++) {
			if (map[i][j] == ' ') {	
				if (i == 0) {
					makeRandomShape random;
					map[i][j] = random.getShape();
				}
				else {
					map[i][j] = map[i - 1][j];
					map[i - 1][j] = ' ';
				}
			}
		}
	}
}
bool MapManager::hasEmptyBlock()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == ' ') return true;
		}
	}
	return false;
}