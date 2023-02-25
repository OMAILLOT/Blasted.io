#include "MeleeEnemi.h"
#include "Tools.h"

MeleeEnemi::MeleeEnemi(GameColors& gameColors) {
	healthPoint = 100;
	speed;

	enemiRenderer.setRadius(25.f);
	enemiRenderer.setFillColor(gameColors.enemyColor);
	enemiRenderer.setOutlineColor(gameColors.playerOutline);
	enemiRenderer.setOutlineThickness(2);
}

MeleeEnemi::~MeleeEnemi()
{

}

void MeleeEnemi::EnemyMovement(sf::Vector2f positionToGo)
{
	float velx = -sin((3.14 / 180) * positionToGo.x) * 5;
	float vely = cos((3.14 / 180) * positionToGo.y) * 5;
	float angleOnPlayer = -atan2(positionToGo.x - (enemiRenderer.getPosition().x + enemiRenderer.getRadius()), positionToGo.y - enemiRenderer.getPosition().y - enemiRenderer.getRadius()) * 180 / 3.14159; //angle in degrees of rotation for sprite
	enemiRenderer.setRotation(angleOnPlayer);
	enemiRenderer.setPosition(enemiRenderer.getPosition() + (positionToGo - enemiRenderer.getPosition()) * 2.0f);

}

void MeleeEnemi::OnCollisionEnter()
{
}

