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
	sf::Clock clockForLevelUpEnnemis;

	float delayOnSpawnEnemy;
	float delaySafeTimeBetweenRound;

	int numberOfEnnemisLevelUp;
	float delayBeforeLevelUpEnnemis;

	float speedEnnemisIncrease;
	float sizeEnnemisIncrease;
	int lifePointEnnemisIncrease;

	vector<MeleeEnemi*> ennemisInScene;

	void TimeToSpawnEnnemy(GameColors& gameColors, Player& player);
	void AllEnnemisMovement(GameWindow& gameWindow, Player& player, GameColors& gamecolors, GameState& gameState);
	void TimeToLevelUpEnnemis();

	static EnnemisManager* instancePtr;
	EnnemisManager(const EnnemisManager& obj) = delete;

    static EnnemisManager& getInstance()
    {
		static EnnemisManager INSTANCE;
		return INSTANCE;
    }
};