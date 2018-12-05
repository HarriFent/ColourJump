#pragma once

class View;

class Button
{
public:
	Button();
	~Button();
	void getRect(int& x, int& y, int& width, int& height) { x = this->x; y = this->y; width = this->w; height = this->h; }
	void getPos(int& x, int& y) { x = this->x; y = this->y; }
	void setRect(int x, int y, int width, int height) { this->x = x; this->y = y; this->w = width; this->h = height;}
	void setDown(bool down) { this->down = down; }

	void draw(View * v);
private:
	int x, y, w, h;
	bool down;
};

