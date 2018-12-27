#include "Block.h"

#include "View.h"

Block::Block()
{
	setDamage(0x00ffff00);
}


Block::~Block()
{
}

void Block::draw(View * v)
{
	v->setPenColour(v->clBlack, 2);
	v->selectBackColour(dmg);
	v->drawRectangle(x, y, w, h, true);
}
