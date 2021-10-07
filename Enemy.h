#pragma once

#include "Bullets.h"
#include <iostream> 
#include <random> 
#include <string>
#include <sstream>
#include <SFML/Audio.hpp>



class Enemy
{
private:
	sf::Sprite Sprite;
	//sf::Texture *Texture; 

	sf::Vector2f Direction;


	float movementSpeed = static_cast<float>(rand() % 5 + 2); 
	float HP = 2.f; 

	


public:
	//Constructor
	Enemy(sf::Texture* Texture, float pos_x, float pos_y);

	//Destructor
	virtual ~Enemy(); 


	//Getters
	const float&getHP() const;

	void takeDamage();
	 
	
	//Initializers

	void Update();
	void Render(sf::RenderTarget * Target); 

	const sf::FloatRect getBounds() const;;
	void setPosition(const sf::Vector2f pos); //Functions Overloaded Intentionally
	void setPosition(const float x, const float y);


};

