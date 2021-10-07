#include "Enemy.h"
#include <SFML/Audio.hpp>




Enemy::Enemy(sf::Texture * Texture, float pos_x, float pos_y)
{

	this->Sprite.setTexture(*Texture); 
	this->Sprite.setPosition(pos_x, pos_y);
	this->Sprite.setScale(2.5f, 2.5f); 

	 


}



Enemy::~Enemy()
{

}








const float& Enemy::getHP() const
{
	return this->HP; 
}

void Enemy::takeDamage()
{
	this->HP -= 1.f; 
}


void Enemy::Update()
{
	this->Sprite.move(0.f, this->movementSpeed);
}

void Enemy::Render(sf::RenderTarget* Target)
{
	Target->draw(this->Sprite); 

}

const sf::FloatRect Enemy::getBounds() const
{
	return this->Sprite.getGlobalBounds();
}

void Enemy::setPosition(const sf::Vector2f pos)
{
	this->Sprite.setPosition(pos);
}

void Enemy::setPosition(const float x, const float y)
{
	this->Sprite.setPosition(x, y);
}


