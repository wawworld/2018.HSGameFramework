#pragma once
#include "SDL.h"
//#include "TextureManager.h" // checked

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"

#include <vector>

class Game
{
public:
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update(); // checked
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }  // checked : 11
	// checked : 11											
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	Game() {} // checked : 11
	static Game*	s_pInstance; // checked : 11
	SDL_Window *	m_pWindow;
	SDL_Renderer*	m_pRenderer;
	bool			m_bRunning;


	// checked.10
	std::vector<GameObject*> m_gameObjects;
	// checked.11
	//GameObject* m_go;
	//GameObject* m_player;
	//GameObject* m_enemy;
};

typedef Game TheGame; // checked : 11
