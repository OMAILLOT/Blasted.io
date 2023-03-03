#pragma once
#include <SFML/Graphics.hpp>
#include "Colors.h"
class Bullet
{
public:
	sf::Vector2f bulletSpeed;
	sf::CircleShape bulletShape;

	float bulletSpeedIncrease;

	sf::Clock clock;
	float delay = 0.7f;

	Bullet(GameColors& gameColors, sf::Vector2f position, float rotation, float increaseBulletSpeed);
	~Bullet();
	void BulletMoove(vector<Bullet*>& playerMagasin);
	void TimeBeforeDestroyBullet(vector<Bullet*>& playerMagasin);
};

