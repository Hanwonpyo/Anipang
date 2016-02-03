#ifndef patternChecker_H
#define patternChecker_H

#include "MapManager.h"
#include "Block.h"
#include <vector>

class patternChecker {

private:
	int x, y;
	char shape;
	bool check=false;
	vector<Block> vec_delete;

public:
	vector<Block> getVector();
	bool checkPang(int x,int y,char shape);
	bool checkLeft();
	bool checkRight();
	bool checkUp();
	bool checkDown();
};
#endif