#include "Block.h"
#include <iostream>
using namespace std;
Block::Block(int x, int y, char shape)
{
	this->x = x;
	this->y = y;
	this->shape = shape;
}
int Block::getX()
{
	return this->x;
}
int Block::getY()
{
	return this->y;
}
bool Block::isnearBlock(Block B)
{
	if((this->x != B.getX()) && (this->y != B.getY()))
		return false;
	if (abs(this->x - B.getX()) !=1 && abs(this->y - B.getY()) !=1)
		return false;
	return true;
}