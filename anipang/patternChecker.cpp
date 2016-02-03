#include "patternChecker.h"

bool patternChecker::checkPang(int x,int y,char shape)
{
	this->x = x;
	this->y = y;
	this->shape = shape;
	this->check = false;

	if (this->checkUp() || this->checkRight() || this->checkLeft() || this->checkDown()) {
		vec_delete.push_back(Block(x, y, shape));
		this->check = true;
	}
	if (this->check == true)
		return true;
	return false;
}
bool patternChecker::checkUp()
{
	int count=0;
	for (int i = y-1; i >= 0; i--) {
		if (MapManager::GetInstance()->getmapValue(x, i) == shape) {
			vec_delete.push_back(Block(x, i, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2)
		return true;
	return false;
}
bool patternChecker::checkRight()
{
	int count = 0;
	for (int i = x+1; i < 10; i++) {
		if (MapManager::GetInstance()->getmapValue(i, y) == shape) {
			vec_delete.push_back(Block(i, y, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2)
		return true;
	return false;
}
bool patternChecker::checkLeft()
{
	int count = 0;
	for (int i = x-1; i >= 0; i--) {
		if (MapManager::GetInstance()->getmapValue(i, y) == shape) {
			vec_delete.push_back(Block(i, y, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2)
		return true;
	return false;
}
bool patternChecker::checkDown()
{
	int count = 0;
	for (int i = y+1; i < 10; i++) {
		if (MapManager::GetInstance()->getmapValue(x, i) == shape) {
			vec_delete.push_back(Block(x, i, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2)
		return true;
	return false;
}
vector<Block> patternChecker::getVector()
{
	return vec_delete;
}