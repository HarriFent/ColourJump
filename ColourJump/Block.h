#pragma once

class View;

class Block
{
public:
	Block();
	~Block();
	void draw(View * v);

	void getRect(int& x, int& y, int& width, int& height) { x = this->x; y = this->y; width = this->w; height = this->h; }
	void getPos(int& x, int& y) { x = this->x; y = this->y; }
	int getDamage() { return this->dmg; }

	void setRect(int x, int y, int width, int height) { this->x = x; this->y = y; this->w = width; this->h = height; }
	void incDamage();
	void setDamage(int dmg) { this->dmg = dmg; }

private:
	int x, y, w, h, dmg;
};

