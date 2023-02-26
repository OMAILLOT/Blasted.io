#pragma once
#include <SFML/Graphics.hpp>
#include "MeleeEnemi.h"
#include "Player.h"
#include "GameWindow.h"
class EnnemisManager
{
    EnnemisManager();
public :
	sf::Clock clockDelayOnSpawnEnemy;
	sf::Clock clockSafeTimeBetweenRound;

	float delayOnSpawnEnemy;
	float delaySafeTimeBetweenRound;


	vector<MeleeEnemi*> ennemisInScene;

	void TimeToSpawnEnnemy(GameColors& gameColors, Player& player);
	void AllEnnemisMovement(GameWindow& gameWindow, Player& player);


	static EnnemisManager* instancePtr;
	EnnemisManager(const EnnemisManager& obj) = delete;
    static EnnemisManager& getInstance()
    {
		static EnnemisManager INSTANCE;
		return INSTANCE;
    }
};