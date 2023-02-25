#pragma once
#include "Enemis.h"
class MeleeEnemi : public Enemis
{
	MeleeEnemi(GameColors& gameColors);
	~MeleeEnemi();
	void EnemyMovement(sf::Vector2f positionToGo);
	void OnCollisionEnter();

};

