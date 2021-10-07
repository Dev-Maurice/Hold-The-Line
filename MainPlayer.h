#pragma once

#include "Enemy.h"
#include <iostream> 
#include <random> 
#include <string>
#include <sstream>
#include <SFML/Audio.hpp>


class MainPlayer
{
private:
	sf::Sprite Sprite;
	sf::Texture Texture;

	float attackCooldown; 
	float attackCooldownMax; 

	int HP;
	int HPMAX; 

	

public:
	MainPlayer();
	virtual ~MainPlayer(); 


	//Functions
	const bool canAttack(); 

	//Sets
	void setPosition(const sf::Vector2f pos); //Functions Overloaded Intentionally
	void setPosition(const float x, const float y);
	void setHP(const int hp);
	void loseHP(const int losthp);

	//Accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHP() const; 
	const int& getHPMax() const; 

	
	//Initializers:
	void initializeVariables(); 
	void initializeTexture();
	void initializeSprite(); 

	

	//Updates
	void Update();
	void updateMovement(); 
	void updateCooldown(); 


	//Rendering
	void Render(sf::RenderTarget & Target); 


};

