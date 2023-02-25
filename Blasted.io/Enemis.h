#pragma once
#include "SFML/Graphics.hpp"
#include "Colors.h"
class Enemis
{
public:

	int healthPoint;
	sf::Vector2f speed;
	sf::CircleShape enemiRenderer;
	virtual void EnemyMovement();
	virtual void OnCollisionEnter();

};

