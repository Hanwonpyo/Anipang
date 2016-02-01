#include "makeRandomShape.h"

makeRandomShape::makeRandomShape()
{
	random_number = rand() % 4 + 1;
	shape = matchingShape(random_number);
}
char makeRandomShape::matchingShape(int number)
{
	if (number == 0) return '@';
	else if (number == 1) return '#';
	else if (number == 2) return '%';
	else return '&';
}
char makeRandomShape::getShape()
{
	return shape;
}