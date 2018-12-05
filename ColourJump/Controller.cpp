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

void Controller::updatePlayer(Player & p)
{
	if (!p.getGrounded() && p.getVelY() < 20) {
		p.setVel(p.getVelX() , p.getVelY() + 0.5);
	}

	p.setPos(xMouse, p.getY() + p.getVelY());

}

void Controller::updateButton(Button & b)
{
	int bx, by, bw, bh;
	b.getRect(bx,by,bw,bh);
	b.setDown(xMouse >= bx && xMouse <= bx + bw && yMouse >= by && yMouse <= by + bh);
}

void Controller::updateBlock(Model * m)
{
}




