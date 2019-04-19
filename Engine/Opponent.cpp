#include "Opponent.h"

Opponent::Opponent(int xstart, int ystart)
{
	x = xstart;
	y = ystart;
}

void Opponent::DrawOpponent(int x0, int y0, Graphics & gfx)
{
	gfx.DrawRect2(x0, y0, width, height, Colors::Magenta);
}

void Opponent::UpdateOpponent(Ball& ball)
{
	if (ball.isBallActive())
	{
		if (ball.GetY() > y && ball.GetX() > 280)
		{
			y = y + yspeed;
		}
		else if (ball.GetY() < y && ball.GetX() > 280)
		{
			y = y - yspeed;
		}
	}
}

int Opponent::GetX()
{
	return x;
}

int Opponent::GetY()
{
	return y;
}

int Opponent::GetWidth()
{
	return x + width;
}

int Opponent::GetHeight()
{
	return y + height;
}

void Opponent::Collision(Ball & ball)
{
	
	if (ball.GetX()+20 > x && ball.GetX()+20 < x+width && ball.GetY()<y+height && ball.GetY()+20 > y)
		{
			ball.xspeed = -5;
		}
}
