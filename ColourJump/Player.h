#pragma once

class View;

class Player
{
public:
	Player();
	~Player();
	void draw(View * v);

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getRadius() { return this->r; }
	bool getGrounded() { return this->grounded; }
	double getVelX() { return this->dx; }
	double getVelY() { return this->dy; }

	void setSize(int r) { this->r = r; }
	void setPos(int x, int y) { this->x = x; this->y = y; }
	void setVel(double dx, double dy) { this->dx = dx; this->dy = dy; }
	void setGrounded(bool grounded) { this->grounded = grounded; }

	bool isColliding(int x, int y, int w, int h);

private:
	int x, y, r;
	double dx, dy;
	bool grounded;
};

