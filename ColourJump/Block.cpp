#include "Block.h"

#include "View.h"

Block::Block()
{
	setDamage(0xffff00);
}


Block::~Block()
{
}

void Block::incDamage() 
{
	if (dmg != 0xffffff) {
		this->dmg++; 
	}
}

void Block::draw(View * v)
{
	v->setPenColour(v->clBlack, 2);
	v->selectBackColour(dmg);
	v->drawRectangle(x, y, w, h, true);
}
