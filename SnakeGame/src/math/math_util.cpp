#include "math_util.h"
#include <math.h>
#include <cstdlib>
#include <ctime>



float Math::genRandNum(int min, int max) 
{
	if (min > max)
		return (float)max;

	srand((int)time(0));

	int random_integer = min + rand() % max;

	
	return ((float)random_integer / 10);
}

bool Math::compare(float a, float b)
{
	//approx lee-way of 0.01
	float absDiff = (float)fabs(a - b);

	if (absDiff < 0.01f)
		return true;
	else
		return false;

}