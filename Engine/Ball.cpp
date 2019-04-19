#include "Ball.h"


Ball::Ball(int xstart, int ystart)
{
	x = xstart;
	y = ystart;
}

void Ball::DrawBall(int x0, int y0,Graphics & gfx)
{
	gfx.DrawRect2(x0, y0, dimensions, dimensions, Colors::White);
}

void Ball::Update(Mouse & mouse)
{
	
	if (!active)
	{
		x = 280;
		y = 255;
	}
	if (!active && mouse.LeftIsPressed())
	{
		active = true;
	}

	if (active)
	{
		x += xspeed;
		y += yspeed;
	}
}


int Ball::GetX()
{
	return x;
}

int Ball::GetY()
{
	return y;
}

int Ball::GetYSpeed()
{
	return yspeed;
}

int Ball::GetXSpeed()
{
	return xspeed;
}

void Ball::BindBall()
{
	if (x <= 0 || x+dimensions >= Graphics::ScreenWidth)
	{
		active = false;
	}

	if (y <= 0)
	{
		yspeed+=5;
	}
	if (y+dimensions >= Graphics::ScreenHeight)
	{
		yspeed -= 5;
	}
}

bool Ball::isBallActive()
{
	return active;
}


