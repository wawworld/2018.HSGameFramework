#include "SDLGameObject.h"
#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

//void Player::load(int x, int y, int width, int height,
//	std::string textureID)
//{
//	GameObject::load(x, y, width, height, textureID);
//	// �� �ڵ尡 �ǹ̰� ������? ���ڵ尡 �����ٸ�, �ڵ����� �θ� ȣ��?? 
//}

void Player::draw() // checked 11 : ���ں��� 
{
	SDLGameObject::draw(); // we now use SDLGameObject
	// �� �ڵ尡 �ǹ̰� ������? ���ڵ尡 �����ٸ�, �ڵ����� �θ� ȣ��?? 
}

void Player::update()
{
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
}