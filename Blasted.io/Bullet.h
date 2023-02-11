#pragma once
#include <SFML/Graphics.hpp>
#include "Colors.h"
class Bullet
{
	sf::CircleShape bulletShape;
	Bullet(GameColors& gameColors);
	~Bullet();
	void BulletMoove(float bulletSpeed);
};

