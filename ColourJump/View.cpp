#include "View.h"
#include "EasyGraphics.h"
#include <iomanip>

View::View(HINSTANCE hInstance)
{
	setImmediateDrawMode(false);
	create(hInstance, SCREENWIDTH, SCREENHIGHT, 40, false);
	gameState = GAME;
	setTimer(1,1);
	resetCursorPos();
	waitForClose();
}

View::~View()
{
}

void View::onDraw()
{
	clrscr(0x00e6ebf2);
	switch (gameState)
	{
	case MENU:
		model.playButton.draw(this);
		break;
	case GAME:

		//Draw Score
		int scrWidth, scrHeight;
		getDrawableSize(scrWidth, scrHeight);
		gotoxy((scrWidth / getPixelsPerColumn() / 2) - 2, 0);
		selectTextColour(clBlack);
		selectBackColour(0x00e6ebf2);
		(*this) << std::setfill('0') << std::setw(4) << std::fixed << std::setprecision(0) << model.getScore();

		//Draw player
		model.player.draw(this);

		//draw blocks
		for (Block b : model.blocks)
		{
			b.draw(this);
		}
		break;

	case GAMEOVER:

		break;
	}
	

	EasyGraphics::onDraw();
}

void View::onMouseMove(UINT nFlags, int x, int y)
{
	controller.SetMousePos(x, y);
	resetCursorPos();
	EasyGraphics::onMouseMove(nFlags, x, y);
}

void View::resetCursorPos() 
{
	POINT cursorPos;
	HWND handle = FindWindowA("ColourJump", "Colour Jump");
	cursorPos.x = SCREENWIDTH / 2;
	cursorPos.y = SCREENHIGHT / 2;
	ClientToScreen(handle, &cursorPos);
	SetCursorPos(cursorPos.x, cursorPos.y);
}

void View::onLButtonDown(UINT nFlags, int x, int y)
{
	if (model.player.getGrounded())
	{
		model.player.setVel(model.player.getVelX(), -16);
		model.player.setGrounded(false);
	}
}

void View::onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == 27) {
		exit(0);
	}
	EasyGraphics::onKeyDown(nChar, nRepCnt, nFlags);
}

void View::onTimer(UINT nIDEvent)
{
	switch (gameState)
	{
	case MENU:
		while (ShowCursor(true) >= 0);
		controller.updateButton(model.playButton);
		break;
	case GAME:
		while (ShowCursor(false) >= 0);
		//Player controls
		controller.updatePlayer(model.player);

		//Block control
		controller.updateBlocks(model);

		//Score Control

		break;
	case GAMEOVER:

		break;
	}
	
	onDraw();
	EasyGraphics::onTimer(nIDEvent);
}
