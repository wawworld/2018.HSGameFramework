#pragma once
#include <SDL.h>
#include <map>

class TextureManager
{
private:
	std::map<std::string, SDL_Texture*> m_textureMap;

	static  TextureManager* s_pInstance; // checked.08
	TextureManager() {} // checked.08
public:
	// checked.08
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
};

// checked.08
typedef TextureManager TheTextureManager;
