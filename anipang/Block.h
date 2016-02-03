#ifndef Block_H
#define Block_H

class Block {

private:
	int x;
	int y;
	char shape;
public:
	Block(int x, int y, char shape);
	int getX();
	int getY();
	bool isnearBlock(Block B);
};
#endif