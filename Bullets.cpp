#include "Bullets.h"
#include <SFML/Audio.hpp>

Bullets::Bullets()
{
	
}

Bullets::Bullets(sf::Texture* texture, float posx, float posy, float dirX, float dirY, float movement_speed)
{
	this->Shape.setTexture(*texture); 
	this->Shape.setPosition(posx, posy); 
	this->Direction.x = dirX;
	this->Direction.y = dirY;
	this->movementSpeed = movement_speed;


}

Bullets::~Bullets()
{

}

const sf::FloatRect Bullets::getBounds() const
{
	return this->Shape.getGlobalBounds(); 
}

void Bullets::Update()
{
	//Update Movement
	this->Shape.move(this->movementSpeed * this->Direction);

}

void Bullets::Render(sf::RenderTarget* Target)
{
	Target->draw(this->Shape); 
}

