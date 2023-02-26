#include "MeleeEnemi.h"
#include "Tools.h"

MeleeEnemi::MeleeEnemi(GameColors& gameColors,sf::Vector2f position, float rotation) {
	healthPoint = 100;
	speed;

	enemiRenderer.setRadius(25.f);
	enemiRenderer.setFillColor(gameColors.enemyColor);
	enemiRenderer.setOutlineColor(gameColors.playerOutline);
	enemiRenderer.setOutlineThickness(2);
	enemiRenderer.setPosition(position);
	enemiRenderer.setRotation(rotation);
}

MeleeEnemi::~MeleeEnemi()
{

}

void MeleeEnemi::MeleeEnemyMovement(sf::Vector2f positionToGo, Player& player)
{
	//float velx = -sin((3.14 / 180) * positionToGo.x) * 5;
	//float vely = cos((3.14 / 180) * positionToGo.y) * 5;
	float angleOnPlayer = -atan2(positionToGo.x - (enemiRenderer.getPosition().x + enemiRenderer.getRadius()), positionToGo.y - enemiRenderer.getPosition().y - enemiRenderer.getRadius()) * 180 / 3.14159; //angle in degrees of rotation for sprite
	enemiRenderer.setRotation(angleOnPlayer);
	//enemiRenderer.setPosition(enemiRenderer.getPosition() + (positionToGo - enemiRenderer.getPosition()) * 2.0f);
	//float enemiRotation = -atan2(player.playerRenderer.getPosition().x, player.playerRenderer.getPosition().y) * 180 / 3.14159; //angle in degrees of rotation for sprite
	//enemiRenderer.setRotation(enemiRotation);
	float velx = -sin((3.14 / 180) * enemiRenderer.getRotation()) * 1;
	float vely = cos((3.14 / 180) * enemiRenderer.getRotation()) * 1;
	enemiRenderer.move(velx, vely);

}

void MeleeEnemi::OnCollisionEnter()
{
}

