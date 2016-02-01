#include "MapManager.h"
#include "Block.h"
#include <vector>

class patternChecker {

private:
	int x, y;
	int number;
	char shape;
	bool check;
	vector<Block> vec_delete;

public:
	patternChecker();
	patternChecker(int x, int y, int shape);
	void checkLeft();
	void checkRight();
	void checkUp();
	void checkDown();
};