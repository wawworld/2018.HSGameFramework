#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams),
	m_position(pParams->getX(), pParams->getY()),			// checked.12
	m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)		// checked.12
{
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
}

// checked.12
void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),		// checked.12
		m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer());
}
