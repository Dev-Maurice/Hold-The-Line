#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>



class Bullets
{
private:
	sf::Sprite Shape; 
	sf::Texture* Texture; 

	sf::Vector2f Direction; 
	float movementSpeed; 

public:
	Bullets(); 
	Bullets(sf::Texture* texture, float posx, float posy, float dirX, float dirY, float movement_speed);
	virtual ~Bullets(); 

	//Accessor
	const sf::FloatRect getBounds() const;

	void Update();
	void Render(sf::RenderTarget* Target); 

};

