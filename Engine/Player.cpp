#include "Player.h"


void Player::MoveBat(Mouse & mouse)
{
	y = mouse.GetPosY();
}

void Player::DrawBat(int x0, int y0, Graphics & gfx)
{
	gfx.DrawRect2(x0, y0, width, height, Colors::Green);
}

Player::Player(int xstart, int ystart)
{
	x = xstart;
	y = ystart;
}

int Player::GetX()
{
	return x;
}

int Player::GetY()
{
	return y;
}

int Player::GetWidth()
{
	return x+width;
}

int Player::GetHeight()
{
	return y+height;
}

void Player::BindPlayer()
{
	if (y <= 0)
	{
		y = 0;
	}
	if (y+height >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight-height;
	}
}

void Player::Collision(Ball & ball)
{
	if (ball.GetX()< x+width && ball.GetX() > x)
	{
		ball.xspeed = 5;
	}
}

