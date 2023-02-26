#pragma once
#include "SFML/Graphics.hpp"
#include "Colors.h"
class Ennemis
{
public:

	int healthPoint = 3;
	int originalLifePoint;
	float speed;
	sf::CircleShape enemiRenderer;
	virtual void EnnemyMovement();
	virtual void OnCollisionEnter();

};

