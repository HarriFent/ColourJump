#include "Player.h"
#include "View.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::draw(View * v)
{
	//Main red Ball
	v->setPenColour(v->clBlack, 2);
	v->selectBackColour(0x004f4fdd);
	v->drawCircle(x, y, r, true);

	//Shiny White bit on ball
	v->setPenColour(0x00b2b2ff, 0);
	v->selectBackColour(0x00b2b2ff);
	v->drawCircle(x-(r/4), y - (r / 4), r/2, true);
	v->setPenColour(0x004f4fdd, 0);
	v->selectBackColour(0x004f4fdd);
	v->drawCircle(x - (r / 6), y - (r / 6), r/2, true);
}

Side Player::isColliding(Block b)
{
	int bx, by, bw, bh;
	b.getRect(bx, by, bw, bh);
	if (x >= bx && x <= bx + bw && y + r >= by && y + r <= by + bh)
	{
		return BOTTOM;
	}
	else if (x >= bx && x <= bx + bw && y - r >= by && y - r <= by + bh)
	{
		return TOP;
	}
	else if (x - r >= bx && x - r <= bx + bw && y >= by && y <= by + bh)
	{
		return LEFT;
	}
	else if (x + r >= bx && x + r <= bx + bw && y >= by && y <= by + bh)
	{
		return RIGHT;
	}
	else
	{
		return NONE;
	}
}
