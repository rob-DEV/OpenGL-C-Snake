#pragma once
#ifndef GLEW_H
#define GLEW_H
#include <glew.h>
#endif
class Shader
{
public:
	Shader(GLchar* shaderGLSL);
	~Shader();

	const GLchar* shaderSource;

};

