#include "renderer.h"

void glfw_error_callback(int error, const char* description)
{
	//CONSOLE->LogAndFile("GLFW Error: %d - %s", error, description);
}

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);

	if (key == GLFW_KEY_W)
		SNAKE->snakeDirection = UP;
	if (key == GLFW_KEY_A)
		SNAKE->snakeDirection = LEFT;
	if (key == GLFW_KEY_S)
		SNAKE->snakeDirection = DOWN;
	if (key == GLFW_KEY_D)
		SNAKE->snakeDirection = RIGHT;
}

Renderer* Renderer::m_pThis = NULL;

Renderer::Renderer()
{
	//initalize openGL and GLFW
	initGLFW();
	initGLEW();

	//initalize shaders
	GLSL_vertexShader = new Shader(R"glsl(
    #version 450 core
    in vec2 position;
    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    }
	)glsl");

	GLSL_fragmentShader = new Shader(R"glsl(
    #version 450 core
    out vec4 outColor;
    uniform vec3 triangleColor;
    void main()
    {
        outColor = vec4(triangleColor, 1.0);
    }
	)glsl");
}
Renderer::~Renderer()
{
	delete GLSL_vertexShader;
	delete GLSL_fragmentShader;
}

Renderer* Renderer::GetRenderer()
{
	if (m_pThis == NULL)
	{
		m_pThis = new Renderer();
	}
	return m_pThis;

}

void Renderer::initGLEW()
{
	// Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	CONSOLE->LogAndFile("GLEW Initalized");
}

void Renderer::initGLFW()
{
	//Initalize GLFW
	if (!glfwInit())
	{
		CONSOLE->LogAndFile("Failed to initiate GLFW");
		exit(EXIT_FAILURE);
	}
	glfwSetErrorCallback(glfw_error_callback);
	Window = initWindow();
	glfwSetKeyCallback(Window, glfw_key_callback);

	CONSOLE->LogAndFile("GLFW Initalized");
}

GLFWwindow* Renderer::initWindow()
{
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	GLFWwindow* gameWindow = glfwCreateWindow(640, 640, "Main", NULL, NULL);

	if (!gameWindow)
	{
		CONSOLE->LogAndFile("Failed to initiate GLFW window \"Main\"");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(gameWindow);
	glfwSwapInterval(1);

	return gameWindow;
}

void Renderer::DrawSquare(GLfloat x, GLfloat y)
{
	/*
	GLfloat vertices[] = {
	-1.0f, -1.0f, //bl
	-0.9f, -1.0f, //br
	-0.9f, -0.9f, //tr
	-1.0f, -0.9f //tl
	};
	*/


	/*
	|       *
	0.1	|
	|
	---------
	0.1
	*/

	//ensure x and y can't clip outside the window
	if (x > 0.9)
		x = 0.9f;
	if (y > 0.9)
		y = 0.9f;

	GLfloat vertices[] = {
		x, y, //bl
		(x + 0.1f), y, //br
		(x + 0.1f), (y + 0.1f), //tr
		x, (y + 0.1f) //tl
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &GLSL_vertexShader->shaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &GLSL_fragmentShader->shaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	GLint uniColor = glGetUniformLocation(shaderProgram, "triangleColor");

	//simple set colour
	glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	// Draw a square
	glDrawArrays(GL_QUADS, 0, 4);
}
void Renderer::DrawSquare(GLfloat x, GLfloat y, int R, int G, int B)
{
	/*
	GLfloat vertices[] = {
	-1.0f, -1.0f, //bl
	-0.9f, -1.0f, //br
	-0.9f, -0.9f, //tr
	-1.0f, -0.9f //tl
	};
	*/


	/*
	|       *
	0.1	|
	|
	---------
	0.1
	*/

	//ensure x and y can't clip outside the window
	if (x > 0.9)
		x = 0.9f;
	if (y > 0.9)
		y = 0.9f;

	GLfloat vertices[] = {
		x, y, //bl
		(x + 0.1f), y, //br
		(x + 0.1f), (y + 0.1f), //tr
		x, (y + 0.1f) //tl
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &GLSL_vertexShader->shaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &GLSL_fragmentShader->shaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	GLint uniColor = glGetUniformLocation(shaderProgram, "triangleColor");

	//simple set colour
	glUniform3f(uniColor, openGL_utils::RGBtoOpenGL(R), openGL_utils::RGBtoOpenGL(G), openGL_utils::RGBtoOpenGL(B));

	// Draw a square
	glDrawArrays(GL_QUADS, 0, 4);
}

void Renderer::renderSnake()
{
	if (!GAME->isRunning)
		return;

	float clampedSnakeSpeed = (SNAKE->snakeSpeed / 10);

	for (int i = SNAKE->snakeParts.size() - 1; i >= 0; i--)
	{

		//out of bounds check
		if ((SNAKE->snakeParts[0]->xPos > 1.0f) || (SNAKE->snakeParts[0]->xPos < -1.0f) || (SNAKE->snakeParts[0]->yPos > 1.0f) || (SNAKE->snakeParts[0]->yPos < -1.0f))
			GAME->Stop();


		if (i == 0)
		{
			//if its the head (1st) change colour to red
			if (SNAKE->snakeDirection == UP)
			{
				SNAKE->snakeParts[i]->yPos = SNAKE->snakeParts[i]->yPos + clampedSnakeSpeed;
				DrawSquare(SNAKE->snakeParts[i]->xPos, SNAKE->snakeParts[i]->yPos, 255, 0, 0);
			}

			if (SNAKE->snakeDirection == DOWN)
			{
				SNAKE->snakeParts[i]->yPos = SNAKE->snakeParts[i]->yPos - clampedSnakeSpeed;
				DrawSquare(SNAKE->snakeParts[i]->xPos, SNAKE->snakeParts[i]->yPos, 255, 0, 0);
			}

			if (SNAKE->snakeDirection == LEFT)
			{
				SNAKE->snakeParts[i]->xPos = SNAKE->snakeParts[i]->xPos - clampedSnakeSpeed;
				DrawSquare(SNAKE->snakeParts[i]->xPos, SNAKE->snakeParts[i]->yPos, 255, 0, 0);
			}

			if (SNAKE->snakeDirection == RIGHT)
			{
				SNAKE->snakeParts[i]->xPos = SNAKE->snakeParts[i]->xPos + clampedSnakeSpeed;
				DrawSquare(SNAKE->snakeParts[i]->xPos, SNAKE->snakeParts[i]->yPos, 255, 0, 0);
			}

			//if the snake collides with itself
			for (uint32_t j = 1; j < SNAKE->snakeParts.size(); j++)
			{
				if ((SNAKE->snakeParts[i]->xPos == SNAKE->snakeParts[j]->xPos) && (SNAKE->snakeParts[i]->yPos == SNAKE->snakeParts[j]->yPos))
				{
					//changing the gamestate stops the threaded loop
					GAME->Stop();
				}
			}
			//if the snakes head collides with a piece of food
			if (Math::compare(SNAKE->snakeParts[0]->xPos, GAME->foodPiece->xPos) && Math::compare(SNAKE->snakeParts[0]->yPos, GAME->foodPiece->yPos))
			{
				//spawn food at a new location
				GAME->foodPiece->GenerateFood();

				//add to the snake
				SNAKE->snakeParts.push_back(new SnakeSegment());

			}


		}
		else
		{
			//all other parts follow this pattern a,b,c,d -> b =a c=b d=c etc
			SNAKE->snakeParts[i]->xPos = SNAKE->snakeParts[i - 1]->xPos;
			SNAKE->snakeParts[i]->yPos = SNAKE->snakeParts[i - 1]->yPos;

			DrawSquare(SNAKE->snakeParts[i]->xPos, SNAKE->snakeParts[i]->yPos);

		}
	}


}

void Renderer::renderFoodPiece()
{
	DrawSquare(GAME->foodPiece->xPos, GAME->foodPiece->yPos, 0, 0, 255);
}

void Renderer::render(int frameRate)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	renderSnake();
	renderFoodPiece();

	glfwSwapBuffers(Window);
	glfwPollEvents();
}
