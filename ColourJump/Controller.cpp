#include "Controller.h"
#include "Model.h"
#include "View.h"

Controller::Controller()
{
	playerSpeed = 6;
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
		p.setVel(p.getVelX() , p.getVelY() + 0.5);
	}

	//Player is moving left or right depending on the mouse;
	if (xMouse > p.getX() + p.getRadius())
	{
		p.setVel(p.getVelX() + 0.4, p.getVelY());
	}
	else if (xMouse < p.getX() - p.getRadius())
	{
		p.setVel(p.getVelX() - 0.4, p.getVelY());
	}
	else
	{
		p.setVel(p.getVelX()/1.3, p.getVelY());
	}
	p.setPos(p.getX() + (int)p.getVelX(), p.getY() + (int)p.getVelY());


}

void Controller::updateButton(Button & b)
{
	int bx, by, bw, bh;
	b.getRect(bx,by,bw,bh);
	b.setDown(xMouse >= bx && xMouse <= bx + bw && yMouse >= by && yMouse <= by + bh);
}

void Controller::updateBlocks(Model& m)
{
	Player& p = m.player;
	for (Block b : m.blocks)
	{
		int x, y, w, h;
		b.getRect(x, y, w, h);
		if (p.isColliding(b) != BOTTOM) p.setGrounded(false);
		switch (p.isColliding(b))
		{
		case TOP :
			p.setVel(p.getVelX(), 0);
			p.setPos(p.getX(), y + h + p.getRadius());
			b.incDamage();
			break;
		case BOTTOM:
			p.setVel(p.getVelX(), 0);
			p.setPos(p.getX(), y - p.getRadius());
			b.incDamage();
			std::cout << b.getDamage();
			p.setGrounded(true);
			break;
		case LEFT:
			p.setVel(0, p.getVelY());
			p.setPos(x + 1 + w + p.getRadius(), p.getY());
			b.incDamage();
			break;
		case RIGHT:
			p.setVel(0, p.getVelY());
			p.setPos(x - 1 - p.getRadius(), p.getY());
			b.incDamage();
			break;
		case NONE:
		default:

			break;
		}
	}
}




