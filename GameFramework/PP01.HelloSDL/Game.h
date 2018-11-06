#pragma once
#include "SDL.h"
//#include "TextureManager.h" // checked

#include "GameObject.h"
#include "Player.h"
class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update(); // checked
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	//TextureManager m_textureManager; // checked.08
	int m_currentFrame; // checked.07

	bool m_bRunning;

	// checked.09
	GameObject m_go;
	Player m_player;

};
