#pragma once
#include "MainPlayer.h"
#include <map>
#include "Bullets.h"
#include <SFML/Audio.hpp>


class Game
{
private:
	//Window
	sf::RenderWindow* GameWindow; //Game Window Object

	//Initialize our Main Player
	MainPlayer* Player1;

	//Resources
	std::map<std::string, sf::Texture*> Textures;
	std::vector<Bullets*> bullets;
	std::vector<Enemy*> enemies; 

	//Sound
	sf::SoundBuffer *buffer;
	sf::Sound *sound;
	sf::SoundBuffer* lvlupbuffer;
	sf::Sound* lvlupsound;
	sf::SoundBuffer* explosionbuffer;
	sf::Sound* explosionsound; 
	

	//Initialize Our Background!
	sf::Sprite Background; 
	sf::Texture BackgroundTexture;
	float MovementSpeed;
	float SpawnTimerMax = 20.f;
	float SpawnTimer = SpawnTimerMax; 
	



public: 
	Game();
	virtual ~Game();
	
	//Main Function For Game:
	void Run(); 


	//Checks
	void updatePollEvents();
	void updateCollision(); 
	void updateBullets(); 
	void updateEnemies(); 
	void updateCombat();
	void updateGUI();


	//GUI
	sf::Font font;
	sf::Text pointText; 
	sf::Text gameoverText; 

	sf::RectangleShape playerHPBar; 
	sf::RectangleShape playerHPBarBack; 

	//Incrementables
	unsigned Points = 0;

	//Render Functions
	void Render(); 
	void renderBackground(); 
	void renderGUI(); 


	//Initializer Functions:
	void initializeTextures();
	void initializeVariable(); 
	void initializeWindow(); 
	void initializePlayerChar(); 
	void initializeBackground(); 
	void initializeEnemies(); 
	void initializeSound();
	void initializeGUI(); 

	

	


};

