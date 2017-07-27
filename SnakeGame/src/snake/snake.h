#pragma once
#include <vector>
#include "..\snake\snake_segment.h"
class Snake
{
public:
	Snake();
	~Snake();

	/*
	* speed of the snake
	*/
	static float snakeSpeed;

	/*
	* current moving direction of the snake
	*/
	int snakeDirection;

	/*
	* vector containing the list of segments which make up the snake 
	*/
	std::vector<SnakeSegment*> snakeParts;
	

};

