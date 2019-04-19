#pragma once
#include "Graphics.h"
#include "Mouse.h"

class Ball
{
private:
	int x;
	int y;
	static constexpr int dimensions = 20;
	bool active = false;
public:
	Ball(int xstart, int ystart);
	void DrawBall(int x0, int y0,Graphics& gfx);
	void Update(Mouse& mouse);
	int GetX();
	int GetY();
	int GetYSpeed();
	int GetXSpeed();
	void BindBall();
	bool isBallActive();
	int yspeed = 5;
	int xspeed = 5;
};

