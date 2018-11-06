#pragma once
#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update() {}; // checked.11
	virtual void clean() {};  // checked.11
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};
