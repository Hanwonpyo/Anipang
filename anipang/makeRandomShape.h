#ifndef makeRandomShape_H
#define makeRandomShape_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#pragma warning(disable:4996)

class makeRandomShape {

private:
	char shape;
	int random_number;

public:
	makeRandomShape();
	char matchingShape(int number);
	char getShape();
};
#endif