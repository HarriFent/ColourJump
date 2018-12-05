#pragma once
#include "EasyGraphics.h"
#include "Model.h"

class View;

class Controller
{
public:
	Controller();
	~Controller();
	int getX() { return this->xMouse; }
	int getY() { return this->yMouse; }
	void SetMousePos(int x, int y) { this->xMouse = x, this->yMouse = y; }

	void updatePlayer(Player& p);
	void updateButton(Button& b);
	void updateBlock(Model& m);

private:
	int xMouse, yMouse;
	int playerSpeed;
};

