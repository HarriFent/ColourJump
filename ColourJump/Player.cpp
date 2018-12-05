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

bool Player::isColliding(int bx, int by, int bw, int bh)
{
	return (x >= bx && x <= bx + bw && y + r >= by && y + r <= by + bh);
}
