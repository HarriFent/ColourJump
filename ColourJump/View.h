#pragma once
#include "EasyGraphics.h"
#include "Model.h"
#include "Controller.h"
#include "Globals.h"

class View : public EasyGraphics
{
public:
	View(HINSTANCE hInstance);
	~View();
	virtual void onDraw();
	virtual void onMouseMove(UINT nFlags, int x, int y);
	virtual void onLButtonDown(UINT nFlags, int x, int y);
	virtual void onTimer(UINT nIDEvent);
	virtual void onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void resetCursorPos();
private:
	Model model;
	Controller controller;

	GameState gameState;
};

