#ifndef MapManager_H
#define MapManager_H

#include "makeRandomShape.h"
#include "patternChecker.h"
#include "Block.h"
#include <vector>
using namespace std;

class MapManager {

private:
	char map[10][10];
	static MapManager* MapManager::mapManager;
public:
	MapManager(void);
	static MapManager* GetInstance();
	void FreeInstance();
	void deleteBlock(vector<Block> vec_delete);
	void swapBlock(int x1, int y1, int x2, int y2);
	void fillMap(int x, int y);
	void shiftBlock();
	bool hasEmptyBlock();
	char getmapValue(int x, int y);
	char* getMap();
	void printMap();
	void makeMap();
	
};
#endif