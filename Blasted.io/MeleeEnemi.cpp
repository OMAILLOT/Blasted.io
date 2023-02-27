#include "MeleeEnemi.h"
#include "Tools.h"
#include "EnnemisManager.h"
#include <iostream>

MeleeEnemi::MeleeEnemi(GameColors& gameColors,sf::Vector2f position, float rotation, float speedEnnemisIncrease) {
	healthPoint = 3;
	originalLifePoint = healthPoint;
	speed = 1;
	enemiRenderer.setOrigin(enemiRenderer.getRadius(), enemiRenderer.getOutlineThickness());
	enemiRenderer.setRadius(25.f);
	enemiRenderer.setFillColor(gameColors.enemyColor);
	enemiRenderer.setOutlineColor(gameColors.playerOutline);
	enemiRenderer.setOutlineThickness(2);
	enemiRenderer.setPosition(position);
	enemiRenderer.setRotation(rotation);
	speed *= speedEnnemisIncrease;
}

MeleeEnemi::~MeleeEnemi()
{

}

void MeleeEnemi::MeleeEnemyMovement(sf::Vector2f positionToGo, Player& player, GameColors& gameColors, GameState& gameState)
{
	float angleOnPlayer = -atan2(positionToGo.x - (enemiRenderer.getPosition().x + enemiRenderer.getRadius()), positionToGo.y - enemiRenderer.getPosition().y - enemiRenderer.getRadius()) * 180 / 3.14159; //angle in degrees of rotation for sprite
	enemiRenderer.setRotation(angleOnPlayer);
	float velx = -sin((3.14 / 180) * enemiRenderer.getRotation()) * speed;
	float vely = cos((3.14 / 180) * enemiRenderer.getRotation()) * speed;
	enemiRenderer.move(velx, vely);
	DetectCollision(player, gameState);
}

void MeleeEnemi::DetectCollision(Player& player, GameState& gameState)
{
	EnnemisManager& ennemisManager = EnnemisManager::getInstance();
	for (int i = 0; i < player.magasin.size(); i++) {
		if (enemiRenderer.getGlobalBounds().intersects(player.magasin[i]->bulletShape.getGlobalBounds()))
		{
			player.magasin[i]->~Bullet();
			player.magasin.erase(player.magasin.begin() + i);
			for (int j = 0; j < ennemisManager.ennemisInScene.size(); j++) {
				if (ennemisManager.ennemisInScene[j] == this) {
					healthPoint--;
					enemiRenderer.setRadius(enemiRenderer.getRadius() / (originalLifePoint / 1.8f));
					if (healthPoint <= 0) {
						player.ennemisDestroy();
						ennemisManager.ennemisInScene[j]->~MeleeEnemi();
						ennemisManager.ennemisInScene.erase(ennemisManager.ennemisInScene.begin() + j);
					}
					return;
				}
			}
		}
	}

	if (enemiRenderer.getGlobalBounds().intersects(player.playerRenderer.getGlobalBounds()))
	{
		player.UpdatePlayerLife(gameState);
		for (int j = 0; j < ennemisManager.ennemisInScene.size(); j++) {
			if (ennemisManager.ennemisInScene[j] == this) {
				//player.playerRenderer.setRadius(player.playerRenderer.getRadius() / (player.originalLifePoint / 2.8f));
				ennemisManager.ennemisInScene[j]->~MeleeEnemi();
				ennemisManager.ennemisInScene.erase(ennemisManager.ennemisInScene.begin() + j);
				return;
			}
		}
	}
}

