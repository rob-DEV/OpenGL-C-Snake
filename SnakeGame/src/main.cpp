#include "console\console.h"
#include "game\definitions.h"
#include "game\game.h"
#include "openGL\renderer\renderer.h"

Console* CONSOLE = Console::GetConsole();

Game* GAME = Game::GetGame();
Snake* SNAKE = Game::GetGame()->snake;
Renderer* RENDERER = Renderer::GetRenderer();



int main() 
{
	double time = 0.0f;

	GAME->Run();


	while (!glfwWindowShouldClose(RENDERER->Window))
	{
		double currentTime = glfwGetTime();

		if (currentTime - time >= 1.0 / 10)
		{
			time = currentTime;
			//called every frame
			RENDERER->render(10);
		}
	}

	glfwTerminate();
	
	return 0;
}