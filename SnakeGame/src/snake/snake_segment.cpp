#include "snake_segment.h"

SnakeSegment::SnakeSegment()
{
	xPos, yPos = 0;
}
SnakeSegment::SnakeSegment(float x, float y)
{
	xPos = x;
	yPos = y;
}

SnakeSegment::~SnakeSegment()
{
}
