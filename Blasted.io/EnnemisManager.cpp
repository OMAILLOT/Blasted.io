#include "EnnemisManager.h"
#include "Tools.h"
#include <iostream>

EnnemisManager::EnnemisManager()
{
}

EnnemisManager::~EnnemisManager()
{
}

void EnnemisManager::TimeToSpawnEnnemy(GameColors& gameColors, Player& player)
{
	if (tools::IsDelayIsExceeded(clockDelayOnSpawnEnemy, 2)) {
		sf::Vector2f enemiPosition(player.playerRenderer.getPosition().x + rand() % 600 + 300, player.playerRenderer.getPosition().y + rand() % 600 + 300);
		float enemiRotation = -atan2(player.playerRenderer.getPosition().x, player.playerRenderer.getPosition().y) * 180 / 3.14159; //angle in degrees of rotation for sprite
		MeleeEnemi* currentMeleeEnemi = new MeleeEnemi(gameColors, enemiPosition, enemiRotation);
		ennemisInScene.push_back(currentMeleeEnemi);
	}
}

void EnnemisManager::AllEnnemisMovement(GameWindow& gameWindow, Player& player)
{
	for (MeleeEnemi* ennemy : ennemisInScene)
	{
		gameWindow.window.draw(ennemy->enemiRenderer);
		sf::Vector2f playerPosition(
									player.playerRenderer.getPosition().x + (player.playerRenderer.getRadius() + player.playerRenderer.getOutlineThickness()*2),
									player.playerRenderer.getPosition().y + (player.playerRenderer.getRadius() + player.playerRenderer.getOutlineThickness()*2));
		ennemy->MeleeEnemyMovement(playerPosition, player);
	}
}
