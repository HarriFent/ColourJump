#include "Block.h"

#include "View.h"

Block::Block()
{
}


Block::~Block()
{
}

void Block::draw(View * v)
{
	v->setPenColour(v->clBlack, 2);
	v->selectBackColour(0x00ffff00);
	v->drawRectangle(x, y, w, h, true);
}
