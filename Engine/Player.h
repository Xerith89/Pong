#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Ball.h"
class Player
{
public:
	void MoveBat(Mouse& mouse);
	void DrawBat(int x0, int y0,Graphics& gfx);
	Player(int xstart, int ystart);
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	void BindPlayer();
	void Collision(Ball& ball);
private:
	int x;
	int y;
	static constexpr int width = 20;
	static constexpr int height = 120;
};

