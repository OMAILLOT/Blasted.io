#pragma once
#include "Enemis.h"
#include "Player.h"
class MeleeEnemi : public Ennemis
{
public:
	float radiusToDecrease;
	MeleeEnemi(GameColors& gameColors, sf::Vector2f position, float rotation, float speedIncrease, float sizeEnnemisIncrease, int lifePointEnnemisIncrease);
	~MeleeEnemi();
	void MeleeEnemyMovement(sf::Vector2f positionToGo, Player& player, GameColors& gameColors, GameState& gameState);
	void DetectCollision(Player& player, GameState& gameState);
	//void feedBackHit(sf::Clock feedBackClock, float BaseRadius);
};

