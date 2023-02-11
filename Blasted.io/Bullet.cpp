#include "Bullet.h"


Bullet::Bullet(GameColors& gameColors)
{
	bulletShape.setRadius(10);
	bulletShape.setFillColor(gameColors.darkGrey);
	bulletShape.setOutlineColor(gameColors.playerOutline);
	bulletShape.setOutlineThickness(1);

	/* playerRenderer.setRadius(25.f);
	playerRenderer.setFillColor(gameColors.blue);
	playerRenderer.setOutlineColor(gameColors.playerOutline);
	playerRenderer.setOutlineThickness(2);*/
}

Bullet::~Bullet()
{
}

void Bullet::BulletMoove(float bulletSpeed)
{
	
}
