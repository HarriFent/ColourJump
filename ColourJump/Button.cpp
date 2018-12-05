#include "Button.h"

#include "View.h"

Button::Button()
{
	down = false;
}


Button::~Button()
{
}

void Button::draw(View * v)
{
	if (down) 
	{
	}
	else
	{
		v->drawBitmap(L"playButton.bmp", x, y, w, h);
	}
}
