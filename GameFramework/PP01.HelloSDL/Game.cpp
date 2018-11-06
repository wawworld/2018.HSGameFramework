#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen)  
{
	// ���� �߰��� �� ��   ( m_bRunning ���� �ڵ� �߰�  )

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // draw color�� render �����
	SDL_RenderPresent(m_pRenderer); // ȭ�� �����ϱ�
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
