#include "patternChecker.h"

bool patternChecker::checkBlock(int x,int y,char shape)
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
bool patternChecker::checkAll()
{
	this->check = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->x = i;
			this->y = j;
			this->shape = MapManager::GetInstance()->getmapValue(i, j);
			if (this->checkUp() || this->checkRight() || this->checkLeft() || this->checkDown()) {
				vec_delete.push_back(Block(x, y, shape));
				this->check = true;
			}
		}
	}
	if (this->check == true)
		return true;
	return false;
}
bool patternChecker::checkUp()
{
	vector <Block> vec_temp;
	int count=0;
	for (int i = y-1; i >= 0; i--) {
		if (MapManager::GetInstance()->getmapValue(x, i) == shape) {
			vec_temp.push_back(Block(x, i, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2) {
		for (int i = 0; i < vec_temp.size(); i++) {
			vec_delete.push_back(vec_temp[i]);
		}
		return true;
	}
	return false;
}
bool patternChecker::checkRight()
{
	vector <Block> vec_temp;
	int count = 0;
	for (int i = x+1; i < 10; i++) {
		if (MapManager::GetInstance()->getmapValue(i, y) == shape) {
			vec_temp.push_back(Block(i, y, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2) {
		for (int i = 0; i < vec_temp.size(); i++) {
			vec_delete.push_back(vec_temp[i]);
		}
		return true;
	}
	return false;
}
bool patternChecker::checkLeft()
{
	vector <Block> vec_temp;
	int count = 0;
	for (int i = x-1; i >= 0; i--) {
		if (MapManager::GetInstance()->getmapValue(i, y) == shape) {
			vec_temp.push_back(Block(i, y, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2) {
		for (int i = 0; i < vec_temp.size(); i++) {
			vec_delete.push_back(vec_temp[i]);
		}
		return true;
	}
	return false;
}
bool patternChecker::checkDown()
{
	vector <Block> vec_temp;
	int count = 0;
	for (int i = y+1; i < 10; i++) {
		if (MapManager::GetInstance()->getmapValue(x, i) == shape) {
			vec_temp.push_back(Block(x, i, shape));
			count++;
		}
		else
			break;
	}
	if (count >= 2) {
		for (int i = 0; i < vec_temp.size(); i++) {
			vec_delete.push_back(vec_temp[i]);
		}
		return true;
	}
	return false;
}
vector<Block> patternChecker::getVector()
{
	return vec_delete;
}