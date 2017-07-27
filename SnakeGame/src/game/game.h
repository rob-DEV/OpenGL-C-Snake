#pragma once
#include "..\snake\snake.h"
#include "..\snake\food.h"

class Game
{
	/*
	* singleton game class
	*/
private:
	Game();
	Game(const Game&) {};             // copy constructor is private

	static Game* m_pThis;

public:
	/**
	*   Funtion to create the instance of Game class.
	*   @return singleton object of Game class..
	*/
	static Game* GetGame();

	/*
	* reference to the snake
	*/
	Snake* snake;

	/*
	* reference to the snake's food
	*/
	Food* foodPiece;

	/*
	* public entry point to initalize the game
	*/
	void Run();

	/*
	* ends the game and memory
	*/
	void Stop();

	/*
	* current state of the game
	*/
	bool isRunning;

};

