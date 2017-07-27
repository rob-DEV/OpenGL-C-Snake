#include "utils.h"

float openGL_utils::RGBtoOpenGL(int a)
{
	if (a > 255)
		return 1.0f;
	else if (a < 0)
		return 0.0f;

	return (float)(a / 255);

}
