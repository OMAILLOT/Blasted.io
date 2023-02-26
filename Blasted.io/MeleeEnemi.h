#pragma once
#include "Enemis.h"
#include "Player.h"
class MeleeEnemi : public Ennemis
{
public:

	MeleeEnemi(GameColors& gameColors, sf::Vector2f position, float rotation);
	~MeleeEnemi();
	void MeleeEnemyMovement(sf::Vector2f positionToGo, Player& player);
	void DetectCollision(Player& player);
	void feedBackHit(sf::Clock feedBackClock, float BaseRadius);
};

