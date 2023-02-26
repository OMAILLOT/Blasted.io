#pragma once
#include <SFML/Graphics.hpp>
#include "MeleeEnemi.h"
#include "Player.h"
#include "GameWindow.h"
class EnnemisManager
{
public :
	sf::Clock clockDelayOnSpawnEnemy;
	sf::Clock clockSafeTimeBetweenRound;

	float delayOnSpawnEnemy;
	float delaySafeTimeBetweenRound;

	vector<MeleeEnemi*> ennemisInScene;
	EnnemisManager();
	~EnnemisManager();
	void TimeToSpawnEnnemy(GameColors& gameColors, Player& player);
	void AllEnnemisMovement(GameWindow& gameWindow, Player& player);
};

