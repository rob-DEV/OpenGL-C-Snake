#include "Game.h"

#ifndef IO_STRING_H
#define IO_STRING_H
#include <iostream>
#include <string>
#endif

#ifndef MATH_UTIL_H
#define MATH_UTIL_H
#endif



Game* Game::m_pThis = NULL;

Game::Game()
{
	//create snake in constructor as main needs the global ref
	snake = new Snake();
}

Game* Game::GetGame()
{
	if (m_pThis == NULL)
	{
		m_pThis = new Game();
	}
	return m_pThis;
}


void Game::Run()
{
	
	isRunning = true;


	foodPiece = new Food();

}
void Game::Stop()
{

	if (isRunning) 
	{
		isRunning = false;

		//destory the snake
		for (int i = 0; i < snake->snakeParts.size(); i++)
		{
			delete snake->snakeParts[i];
		}

		//destory food
		delete snake;
		delete foodPiece;
		delete this;

		exit(EXIT_SUCCESS);
	}

}
