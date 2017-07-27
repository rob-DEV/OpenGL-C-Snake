#pragma once
// Link statically with GLEW
#define GLEW_STATIC

#ifndef GLEW_H
#define GLEW_H
#include <glew.h>
#endif

#ifndef GLFW_H
#define GLFW_H
#include <glfw3.h>
#endif

#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include "..\..\game\definitions.h"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H 
#include "..\..\console\console.h"
extern Console* CONSOLE;
#endif

#ifndef GAME_H
#define GAME_H 
#include "..\..\game\game.h"
#include "..\..\openGL\utils\utils.h"

extern Game* GAME;
#endif

#ifndef SNAKE_H
#define SNAKE_H 
extern Snake* SNAKE;
#endif

#include "..\shader\shader.h"

void glfw_error_callback(int error, const char* description);

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


class Renderer
{
private:
	static Renderer* Renderer::m_pThis;
	Shader* GLSL_vertexShader;
	Shader* GLSL_fragmentShader;
public:
	Renderer();
	~Renderer();

	static Renderer* GetRenderer();

	GLFWwindow* Window;



	void initGLEW();
	void initGLFW();
	GLFWwindow* initWindow();
	void DrawSquare(GLfloat x, GLfloat y);
	void DrawSquare(GLfloat x, GLfloat y, int R, int G, int B);

	void renderSnake();
	void renderFoodPiece();
	void render(int frameRate);
};

