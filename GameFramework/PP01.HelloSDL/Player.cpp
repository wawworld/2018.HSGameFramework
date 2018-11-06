#include "SDLGameObject.h"
#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::draw() // checked 11 : ���ں��� 
{
	SDLGameObject::draw(); // we now use SDLGameObject
	// �� �ڵ尡 �ǹ̰� ������? ���ڵ尡 �����ٸ�, �ڵ����� �θ� ȣ��?? 
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