#include "food.h"



Food::Food()
{
	xPos = Math::genRandNum(-10, -10);
	yPos = Math::genRandNum(-10, -10);
}


Food::~Food()
{
}

void Food::GenerateFood()
{
	xPos = Math::genRandNum(-10, -10);
	yPos = Math::genRandNum(-10, -10);
}