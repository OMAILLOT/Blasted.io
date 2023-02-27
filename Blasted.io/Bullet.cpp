#include "Bullet.h"
#include "Tools.h"
#include <iostream>
#include "Player.h"


Bullet::Bullet(GameColors& gameColors, sf::Vector2f position, float rotation)
{
	
	bulletShape.setRadius(10);
	bulletShape.setFillColor(gameColors.PlayerColor);
	bulletShape.setOutlineColor(gameColors.playerOutline);
	bulletShape.setOutlineThickness(1);
	bulletShape.setOrigin(bulletShape.getRadius(), bulletShape.getRadius());
	bulletShape.setPosition(position);
	bulletShape.setRotation(rotation);
	
}

Bullet::~Bullet()
{
}

void Bullet::BulletMoove(vector<Bullet*>& playerMagasin)
{
	float velx = -sin((3.14 / 180) * bulletShape.getRotation()) * 5;
	float vely = cos((3.14 / 180) * bulletShape.getRotation()) * 5;
	bulletShape.move(velx, vely);
	TimeBeforeDestroyBullet(playerMagasin);
}

void Bullet::TimeBeforeDestroyBullet(vector<Bullet*>& playerMagasin)
{
	if (tools::IsDelayIsExceeded(clock, delay)) {
		for (int i = 0; i < playerMagasin.size(); i++) {
			if (playerMagasin[i] == this) {
				playerMagasin[i]->~Bullet();
				playerMagasin.erase(playerMagasin.begin() + i);
			}
		}
	}
}
