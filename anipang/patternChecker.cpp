#include "patternChecker.h"
#include "MapManager.h"

patternChecker::patternChecker()
{
	this->x = 0;
	this->y = 0;
	this->shape = ' ';
}
patternChecker::patternChecker(int x, int y, int shape)
{
	this->x = x;
	this->y = y;
	this->shape = shape;
}
void patternChecker::checkUp()
{
	for (int i = y; i >= 0; i--) {
		if (MapManager::GetInstance()->getmapValue(x , i)==shape) {
			vec_delete.insert(new Block(x, y, shape));
		}
	}
}
void patternChecker::checkRight()
{
	for (int i = x; i < 9; i++) {
		if (MapManager::GetInstance()->getmapValue(i, y) == shape) {
			vec_delete.insert(new Block(x, y, shape));
		}
	}
}
void patternChecker::checkLeft()
{
	for (int i = x; i >= 0; i--) {
		if (MapManager::GetInstance()->getmapValue(i, y) == shape) {
			vec_delete.insert(new Block(x, y, shape));
		}
	}
}
void patternChecker::checkDown()
{
	for (int i = y; i < 9; i++) {
		if (MapManager::GetInstance()->getmapValue(x, i) == shape) {
			vec_delete.insert(new Block(x, y, shape));
		}
	}
}