#include "MainPlayer.h"



MainPlayer::MainPlayer()
{
	this->initializeVariables(); 
	this->initializeTexture(); //Sprite Needs a Texture Hence Order
	this->initializeSprite(); 

}

MainPlayer::~MainPlayer()
{
}

const bool MainPlayer::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f; 
		return true; 
	}

	return false; 
}

void MainPlayer::setPosition(const sf::Vector2f pos)
{
	this->Sprite.setPosition(pos);
}

void MainPlayer::setPosition(const float x, const float y)
{
	this->Sprite.setPosition(x, y);
}

const sf::Vector2f& MainPlayer::getPos() const
{
	return this->Sprite.getPosition();

}

const sf::FloatRect MainPlayer::getBounds() const
{
	return this->Sprite.getGlobalBounds(); 
}

const int& MainPlayer::getHP() const
{
	return this->HP; 
}

const int& MainPlayer::getHPMax() const
{
	return this->HPMAX; 
}

void MainPlayer::initializeVariables()
{
	//Attack
	this->attackCooldownMax = 10.f; 
	this->attackCooldown = this->attackCooldownMax; 
	
	//Health
	this->HPMAX = 10; 
	this->HP = this->HPMAX; 
}

void MainPlayer::initializeTexture()
{
	//Load Texture From File
	/*
	Note this is a boolean function and
	prints to console in the case of an error
	*/ 
	if (!this->Texture.loadFromFile("Textures/Player.png"))
	{
		std::cout << "Couldn't load Sprite, check MainPlayer::initializeTexture() !";

	}

	
}

void MainPlayer::initializeSprite()
{
	//Set The Texture
	this->Sprite.setTexture(this->Texture);
	this->Sprite.scale(3.f, 3.f); 
	this->Sprite.setPosition(250.f, 500.f); 

}

void MainPlayer::setHP(const int hp)
{
	this->HP = hp;
}

void MainPlayer::loseHP(const int losthp)
{
	this->HP -= losthp;
	if (this->HP < 0)
		this->HP = 0; 
}

void MainPlayer::Update()
{
	this->updateMovement(); 
	this->updateCooldown(); 

}

void MainPlayer::updateMovement()
{
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->Sprite.move(-5.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->Sprite.move(5.f, 0.f); 
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Up
	{
		this->Sprite.move(0.f, -5.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //DOwn
	{
		this->Sprite.move(0.f, 5.f);
	}

}

void MainPlayer::updateCooldown()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.40f; 


}

void MainPlayer::Render(sf::RenderTarget& Target)
{
	Target.draw(this->Sprite); 

}
