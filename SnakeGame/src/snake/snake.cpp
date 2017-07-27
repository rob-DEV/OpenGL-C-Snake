#include "snake.h"


float Snake::snakeSpeed = 1.0f;

Snake::Snake()
{
	//create the head
	this->snakeParts.push_back(new SnakeSegment(0, 0));
}


Snake::~Snake()
{
}
