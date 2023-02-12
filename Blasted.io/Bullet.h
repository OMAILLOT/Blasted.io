#pragma once
#include <SFML/Graphics.hpp>
#include "Colors.h"
class Bullet
{
public:
	sf::Vector2f bulletSpeed;
	sf::CircleShape bulletShape;
	Bullet(GameColors& gameColors, sf::Vector2f position, float rotation);
	~Bullet();
	void BulletMoove();
};

