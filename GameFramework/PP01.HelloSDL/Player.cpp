#include "GameObject.h"
#include "Player.h"

void Player::load(int x, int y, int width, int height,
	std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
}

void Player::update()
{
	m_x -= 1;
}
