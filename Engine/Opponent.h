#pragma once
#include "Graphics.h"
#include "Ball.h"

class Opponent
{
public:
	Opponent(int xstart, int ystart);
	void DrawOpponent(int x0, int y0, Graphics& gfx);
	void UpdateOpponent(Ball& ball);
	void BindOpponent();
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
	void Collision(Ball& ball);
private:
	int x;
	int y;
	int yspeed = 2;
	static constexpr int width = 20;
	static constexpr int height = 120;

};

