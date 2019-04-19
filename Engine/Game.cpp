/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	player(45, 250),
	ball(320, 250),
	opponent(750, 250)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();

}

void Game::UpdateModel()
{
	if (!isGameStarted)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isGameStarted = true;
		}
	}
	if (isGameStarted)
	{
		if (!ball.isBallActive())
		{
			ball.Update(wnd.mouse);
		}
		player.MoveBat(wnd.mouse);
		player.BindPlayer();
		ball.Update(wnd.mouse);
		opponent.UpdateOpponent(ball);
		ball.BindBall();
		opponent.Collision(ball);
		player.Collision(ball);
	}
}

void Game::ComposeFrame()
{
	if (!isGameStarted)
	{
		SpriteCodex::DrawTitle(280, 280, gfx);
	}
	if (isGameStarted)
	{
		player.DrawBat(player.GetX(), player.GetY(), gfx);
		ball.DrawBall(ball.GetX(), ball.GetY(), gfx);
		opponent.DrawOpponent(opponent.GetX(), opponent.GetY(), gfx);
	}
}
