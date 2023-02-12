#include "Bullet.h"
#include "Tools.h"
#include <iostream>


Bullet::Bullet(GameColors& gameColors,sf::Vector2f position, float rotation)
{
	
	bulletShape.setRadius(10);
	bulletShape.setFillColor(gameColors.darkGrey);
	bulletShape.setOutlineColor(gameColors.playerOutline);
	bulletShape.setOutlineThickness(1);
	bulletShape.setOrigin(bulletShape.getRadius(), bulletShape.getRadius());
	bulletShape.setPosition(position);
	bulletShape.setRotation(rotation);
}

Bullet::~Bullet()
{
}

void Bullet::BulletMoove()
{
	float velx = -sin((3.14 / 180) * bulletShape.getRotation()) * 5;
	float vely = cos((3.14 / 180) * bulletShape.getRotation()) * 5;
	bulletShape.move(velx, vely);
}
