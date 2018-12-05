#include "View.h"
#include "EasyGraphics.h"
#include <iomanip>

View::View(HINSTANCE hInstance)
{
	setImmediateDrawMode(false);
	create(hInstance, 1024, 768, 40, false);
	gameState = GAME;
	setTimer(1,1);
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
		for (std::vector<Block>::iterator it = model.blocks.begin(); it != model.blocks.end(); ++it)
		{
			(*it).draw(this);
		}
		break;

	case GAMEOVER:

		break;
	}
	

	EasyGraphics::onDraw();
}

void View::onMouseMove(UINT nFlags, int x, int y)
{
	controller.SetMousePos(x, 650);
	EasyGraphics::onMouseMove(nFlags, x, y);
}

void View::onLButtonDown(UINT nFlags, int x, int y)
{
	model.player.setVel(model.player.getVelX(),-16);
}

void View::onTimer(UINT nIDEvent)
{
	switch (gameState)
	{
	case MENU:
		controller.updateButton(model.playButton);
		break;
	case GAME:
		//Player controls
		controller.updatePlayer(model.player);

		//Block control
		controller.updateBlock(model);

		//Score Control

		break;
	case GAMEOVER:

		break;
	}
	
	onDraw();
	EasyGraphics::onTimer(nIDEvent);
}
