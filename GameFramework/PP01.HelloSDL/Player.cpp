#include "SDLGameObject.h"
#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::draw() // checked 11 : 인자변경 
{
	SDLGameObject::draw(); // we now use SDLGameObject
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
}

void Player::update()
{
	m_acceleration.setX(0.1);
	SDLGameObject::update();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
}