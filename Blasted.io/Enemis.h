#pragma once
#include "SFML/Graphics.hpp"
#include "Colors.h"
class Ennemis
{
public:

	int healthPoint;
	sf::Vector2f speed;
	sf::CircleShape enemiRenderer;
	virtual void EnnemyMovement();
	virtual void OnCollisionEnter();

};

