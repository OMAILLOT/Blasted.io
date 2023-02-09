#include "Player.h"
#include "Map.h"
#include <cmath>
#include <iostream>


Player::Player()
{
}

Player::~Player()
{
}

void Player::InitPlayer(GameColors& gameColors) {
	playerRenderer.setRadius(25.f);
	playerRenderer.setFillColor(gameColors.blue);
	playerRenderer.setOutlineColor(gameColors.playerOutline);
	playerRenderer.setOutlineThickness(2);

	canon.setSize(sf::Vector2f(15,40));
	canon.setFillColor(gameColors.canonColor);
	canon.setOutlineColor(gameColors.canonColorOutline);
	canon.setOutlineThickness(2);


	//gameWindow->InitPlayerOnWindow();
}

void Player::PlayerMovement()
{

	playerSpeed = normalize(playerSpeed);
	
	playerSpeed.x *= PLAYER_SPEED;
	playerSpeed.y *= PLAYER_SPEED;

	playerRenderer.move(playerSpeed);
	canon.move(playerSpeed);
}

sf::Vector2f Player::normalize(sf::Vector2f vector) {
	float length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (length != 0)
		return sf::Vector2f(vector.x / length, vector.y / length);
	else
		return vector;
	return sf::Vector2f();
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
	sf::Vector2f position = window.window.mapPixelToCoords(sf::Mouse::getPosition());
	float mouseAngle = -atan2(position.x - playerRenderer.getPosition().x, position.y - playerRenderer.getPosition().y) * 180 / 3.14159; //angle in degrees of rotation for sprite

	std::cout << mouseAngle << "\n";
	canon.setRotation(mouseAngle);
}

void Player::InitPlayerPosition(float X, float Y)
{
	playerRenderer.setPosition(X, Y);
	//canon.setOrigin((canon.getLocalBounds().width - canon.getOutlineThickness() * 2) / 2,0);
	//canon.setOrigin(canon.getSize().x / 2, canon.getSize().y / 2);
	canon.setPosition(X + playerRenderer.getRadius() - (canon.getLocalBounds().width - canon.getOutlineThickness() * 2) / 2, Y + playerRenderer.getRadius());
	//canon.setOrigin(canon.getTexture()->getSize().x / 2, canon.getTexture()->getSize().y / 2);
	

}