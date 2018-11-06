#pragma once
#include "GameObject.h"
#include <string>

class Enemy : public GameObject
{
public:
// checked : 10
//	void load(int x, int y, int width, int height,
//		std::string textureID);
//	void draw(SDL_Renderer* pRenderer);
	void update();
//	void clean();
};
