#include "EnnemisManager.h"
#include "Tools.h"
#include <iostream>
#include <random>


EnnemisManager::EnnemisManager()
{
	delayOnSpawnEnemy = 1;
	delaySafeTimeBetweenRound = 10;
}

void EnnemisManager::TimeToSpawnEnnemy(GameColors& gameColors, Player& player)
{
	if (tools::IsDelayIsExceeded(clockDelayOnSpawnEnemy, 2)) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(-1.0, 1.0);
		sf::Vector2f enemiPosition(player.playerRenderer.getPosition().x + dis(gen) * (rand() % 10) * 150, player.playerRenderer.getPosition().y + dis(gen) * (rand() % 10) * 150);

		std::cout << dis(gen) * (rand() % 100) << endl;
		float enemiRotation = - atan2(player.playerRenderer.getPosition().x, player.playerRenderer.getPosition().y) * 180 / 3.14159; //angle in degrees of rotation for sprite
		MeleeEnemi* currentMeleeEnemi = new MeleeEnemi(gameColors, enemiPosition, enemiRotation);
		ennemisInScene.push_back(currentMeleeEnemi);
	}
}

void EnnemisManager::AllEnnemisMovement(GameWindow& gameWindow, Player& player, GameColors& gamecolors, GameState& gameState)
{
	for (MeleeEnemi* ennemy : ennemisInScene)
	{
		gameWindow.window.draw(ennemy->enemiRenderer);
		sf::Vector2f playerPosition(
			player.playerRenderer.getPosition().x + player.playerRenderer.getRadius() + player.playerRenderer.getOrigin().x + player.playerRenderer.getOutlineThickness(),
			player.playerRenderer.getPosition().y + player.playerRenderer.getRadius() + player.playerRenderer.getOrigin().x + player.playerRenderer.getOutlineThickness());
		ennemy->MeleeEnemyMovement(playerPosition, player, gamecolors, gameState);
	}
}