#pragma once
class Math
{
public:
	/*
	* generates a float between two values (exclusive)
	*/
	static float genRandNum(int min, int max);

	/*
	* compares to float returning true if they are near equal ~ 0.1f
	*/
	static bool compare(float a, float b);
};

