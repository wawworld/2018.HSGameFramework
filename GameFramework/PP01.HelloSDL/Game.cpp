
#include <SDL_image.h>  // 추가 
#include <iostream> // checked


#include "Game.h"

Game* Game::s_pInstance = 0;


bool Game::init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen)  // checked 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
	}
	else {
		return false; // sdl could not initialize
	}

	m_bRunning = true;  // checked 

	//checked.08   
	if(!TheTextureManager::Instance()->load("assets/animate-alpha.png","animate", m_pRenderer))
	{
		return false;
	}

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);


	// checked.11
	//m_go = new GameObject();
	//m_player = new Player();
	//m_enemy = new Enemy();

	//m_go->load(100, 100, 128, 82, "animate");
	//m_player->load(300, 300, 128, 82, "animate");
	//m_enemy->load(0, 0, 128, 82, "animate");

	//m_gameObjects.push_back(m_go);
	//m_gameObjects.push_back(m_player);
	//m_gameObjects.push_back(m_enemy);
	// checked.11
	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	return true;
}

void Game::update()
{
	//m_go.update();  // checked.09
	//m_player.update();// checked.09
	// checked.10
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::render()
{
	// draw color로 render 지우기
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(); // // checked.11
	}
	SDL_RenderPresent(m_pRenderer); 
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
