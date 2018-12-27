#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "Globals.h"

Controller::Controller()
{
	playerSpeed = 40;
}

Controller::~Controller()
{
}

void Controller::SetMousePos(int x, int y)
{
	this->xMouse = x;
	this->yMouse = y;
}

void Controller::updatePlayer(Player & p)
{
	//Player is in the air and isnt at terminal velocity, increase velocity
	if (!p.getGrounded() && p.getVelY() < 20)
	{
		p.setVel(p.getVelX(), p.getVelY() + 0.5);
	}

	//Player moves depending on the mouse change
	double deltaX = (xMouse - (SCREENWIDTH / 2));
	if (deltaX > playerSpeed) deltaX = playerSpeed;
	if (deltaX < -playerSpeed) deltaX = -playerSpeed;
	if (deltaX == 0)
	{
		p.setVel(p.getVelX() / 1.1, p.getVelY());
	}
	else
	{
		p.setVel(p.getVelX() + (deltaX/16), p.getVelY());
	}

	p.setPos(p.getX() + (int)p.getVelX(), p.getY() + (int)p.getVelY());


}

void Controller::updateButton(Button & b)
{
	int bx, by, bw, bh;
	b.getRect(bx, by, bw, bh);
	b.setDown(xMouse >= bx && xMouse <= bx + bw && yMouse >= by && yMouse <= by + bh);
}

void Controller::updateBlocks(Model& m)
{
	Player& p = m.player;
	p.setGrounded(false);
	for (Block& b : m.blocks)
	{
		int x, y, w, h;
		b.getRect(x, y, w, h);
		switch (p.isColliding(b))
		{
		case TOP:
			p.setVel(p.getVelX(), 0);
			p.setPos(p.getX(), y + h + p.getRadius());
			b.incDamage();
			m.incScore();
			break;
		case BOTTOM:
			p.setVel(p.getVelX(), 0);
			p.setPos(p.getX(), y - p.getRadius());
			p.setGrounded(true);
			b.incDamage();
			m.incScore();
			break;
		case LEFT:
			p.setVel(0, p.getVelY());
			p.setPos(x + 1 + w + p.getRadius(), p.getY());
			b.incDamage();
			m.incScore();
			break;
		case RIGHT:
			p.setVel(0, p.getVelY());
			p.setPos(x - 1 - p.getRadius(), p.getY());
			b.incDamage();
			m.incScore();
			break;
		case NONE:
		default:

			break;
		}
	}
	for (std::vector<Block>::iterator it = m.blocks.begin(); it != m.blocks.end();)
	{
		if (it->getDamage() == 0xffffff)
			it = m.blocks.erase(it);
		else
			++it;
	}
}




