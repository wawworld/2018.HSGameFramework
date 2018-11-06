
#include <SDL_image.h>  // �߰� 
#include <iostream> // checked

#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen)  // checked 
{
	// ���� �߰��� �� ��   ( m_bRunning ���� �ڵ� �߰�  )
	// check :: g_pWindow, g_pRenderer => m_pWindow, m_pRenderer
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


	SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
	//SDL_Surface* pTempSurface = IMG_Load("assets/animate.png");
	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
	SDL_FreeSurface(pTempSurface);

	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	return true;
}

void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}

void Game::render()
{
	// draw color�� render �����
	SDL_RenderClear(m_pRenderer);
	// ���� �簢���� ��� �簢���� ��ġ�� ũ�⿡ ���� ȭ�鿡 �ٸ��� ��Ÿ����  
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	// ȭ�� �����ϱ�
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
