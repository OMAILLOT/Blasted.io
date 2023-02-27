#include "Player.h"
#include "Map.h"
#include <cmath>
#include <iostream>
#include "Tools.h"
GameColors gameColors;


Player::Player()
{
}

Player::~Player()
{
}

void Player::InitPlayer(GameColors& _gameColors) {
	gameColors = _gameColors;
	playerRenderer.setRadius(25.f);
	playerRenderer.setFillColor(gameColors.PlayerColor);
	playerRenderer.setOutlineColor(gameColors.playerOutline);
	playerRenderer.setOutlineThickness(2);

	canon.setSize(sf::Vector2f(15,40));
	canon.setFillColor(gameColors.canonColor);
	canon.setOutlineColor(gameColors.canonColorOutline);
	canon.setOutlineThickness(2);
	gameColors = _gameColors;
	timerForShoot;
	originalLifePoint = lifePoint;
	//gameWindow->InitPlayerOnWindow();
	ennemiesDestroyBeforeLevelUp = 5;
	baseEnnemiesDestroyBeforeLevelUp = ennemiesDestroyBeforeLevelUp;
	delayOnShoot = 0.85f;
	numberOfLevelUp = 5;
	speedIncrease = 1;
}

void Player::PlayerLoop(GameState& gameState, GameWindow& window)
{
	CheckInput(gameState);
	PlayerMovement();
	RotateCanon(window);
}

void Player::PlayerMovement()
{
	playerSpeed = tools::normalize(playerSpeed);
	
	playerSpeed.x *= PLAYER_SPEED + speedIncrease;
	playerSpeed.y *= PLAYER_SPEED + speedIncrease;

	playerRenderer.move(playerSpeed);
	canon.move(playerSpeed);
}

void Player::CheckInput(GameState& gameState) {
	
	if (playerInput.GetButton().left == true)
	{
		playerSpeed.x = -PLAYER_SPEED;

		if (playerRenderer.getPosition().x < -(rows / 2 * WorldCell.getLocalBounds().width))
			playerSpeed.x = 0;
	}
	if (playerInput.GetButton().right == true)
	{
		playerSpeed.x = PLAYER_SPEED;

		if (playerRenderer.getPosition().x > (rows / 2 * WorldCell.getLocalBounds().width) - playerRenderer.getRadius() * 2)
			playerSpeed.x = 0;
	}
	if (playerInput.GetButton().up == true)
	{
		playerSpeed.y = -PLAYER_SPEED;

		if (playerRenderer.getPosition().y < -(columns / 2 * WorldCell.getLocalBounds().height))
			playerSpeed.y = 0;

	}
	if (playerInput.GetButton().down == true)
	{
		playerSpeed.y = PLAYER_SPEED;

		if (playerRenderer.getPosition().y > (columns / 2 * WorldCell.getLocalBounds().height) - playerRenderer.getRadius() * 2)
			playerSpeed.y = 0;
	}
	if (playerInput.GetButton().attack == true)
	{
		Shoot();
	}
	if (playerInput.GetButton().exit == true)
	{
		gameState = GameState::Menu;
	}

	if (playerInput.GetButton().left == false && playerInput.GetButton().right == false) playerSpeed.x = 0;
	if (playerInput.GetButton().up == false && playerInput.GetButton().down == false) playerSpeed.y = 0;
}

void Player::RotateCanon(GameWindow& window)
{
	sf::Vector2f curPos = playerRenderer.getPosition();
	sf::Vector2f position = window.window.mapPixelToCoords(sf::Mouse::getPosition(window.window));
	float mouseAngle = -atan2(position.x - (playerRenderer.getPosition().x + playerRenderer.getRadius()), position.y - playerRenderer.getPosition().y - playerRenderer.getRadius()) * 180 / 3.14159; //angle in degrees of rotation for sprite

	canon.setRotation(mouseAngle);
}

void Player::InitPlayerPosition(float X, float Y)
{
	playerRenderer.setPosition(X, Y);
	canon.setOrigin(canon.getSize().x * 0.5f, -2);

	canon.setPosition(X + playerRenderer.getRadius(), Y + playerRenderer.getRadius());	

}

void Player::Shoot() {
	if (tools::IsDelayIsExceeded(timerForShoot, delayOnShoot)) {
		sf::Vector2f bulletPosition(
			canon.getPosition().x - sin((3.14 / 180) * canon.getRotation()) * canon.getSize().y,
			canon.getPosition().y + cos((3.14 / 180) * canon.getRotation()) * canon.getSize().y
		);

		Bullet* newBullet = new Bullet(gameColors, bulletPosition, canon.getRotation());
		magasin.push_back(newBullet);
	}
}

void Player::UpdatePlayerLife(GameState& gameState)
{
		lifePoint--;
		if (lifePoint > 0) playerRenderer.setFillColor(gameColors.PlayerHitColors[lifePoint]);
		else gameState = GameState::Menu;
}

void Player::ennemisDestroy()
{
	if (numberOfLevelUp > 0) {
		ennemiesDestroyBeforeLevelUp--;
		if (ennemiesDestroyBeforeLevelUp <= 0) {
			ennemiesDestroyBeforeLevelUp = baseEnnemiesDestroyBeforeLevelUp;
			delayOnShoot *= 0.65f;
			speedIncrease += 1;
			numberOfLevelUp--;
		}
	}
}



