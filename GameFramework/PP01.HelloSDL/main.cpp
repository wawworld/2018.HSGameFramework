#include "Game.h"

Game* g_game = 0; // our Game object

int main(int argc, char* args[])
{
	g_game = new Game();
	g_game->init("Chapter 1", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	g_game->clean();
	return 0;

}

/*

bool g_bRunning = false; // this will create a loop

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
void render();

bool init(const char* title, int xpos, int ypos,
	int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else {
		return false; // sdl could not initialize
	}
	return true;
}

void render()
{
	// set to black
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	// clear the window to black
	SDL_RenderClear(g_pRenderer);
	// show the window
	SDL_RenderPresent(g_pRenderer);
}

*/