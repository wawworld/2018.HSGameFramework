
#include <SDL_image.h>  // 추가 
#include <iostream> // checked

#include "Game.h"
#include "TextureManager.h"

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

	//m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer); // checked.08
	//checked.08   
	if(!TheTextureManager::Instance()->load("assets/animate-alpha.png","animate", m_pRenderer))
	{
		return false;
	}

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	return true;
}

void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6)); // checked.07
}

void Game::render()
{
	// draw color로 render 지우기
	SDL_RenderClear(m_pRenderer);
	// 원본 사각형과 대상 사각형의 위치와 크기에 따라 화면에 다르게 나타남…  
	//m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer); // checked.08
	//m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer); // checked.08
	// checked.08
	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82,m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate", 100, 100,128, 82, 1, m_currentFrame, m_pRenderer);

	// 화면 제시하기
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
