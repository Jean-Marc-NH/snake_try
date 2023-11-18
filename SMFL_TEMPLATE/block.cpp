#include "block.hpp"

using namespace std;

Block::Block(int x, int y)
{
	_x = x;
	_y = y;
}

int Block::getX()
{
	return _x;
}

int Block::getY()
{
	return _y;
}