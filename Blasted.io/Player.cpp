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
	playerRenderer.setFillColor(gameColors.blue);
	playerRenderer.setOutlineColor(gameColors.playerOutline);
	playerRenderer.setOutlineThickness(2);

	canon.setSize(sf::Vector2f(15,40));
	canon.setFillColor(gameColors.canonColor);
	canon.setOutlineColor(gameColors.canonColorOutline);
	canon.setOutlineThickness(2);

	timerForShoot;

	//gameWindow->InitPlayerOnWindow();
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
	
	playerSpeed.x *= PLAYER_SPEED;
	playerSpeed.y *= PLAYER_SPEED;

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
	if (WaitBeforeShoot()) {
		sf::Vector2f bulletPosition(
			canon.getPosition().x - sin((3.14 / 180) * canon.getRotation()) * canon.getSize().y,
			canon.getPosition().y + cos((3.14 / 180) * canon.getRotation()) * canon.getSize().y
		);

		Bullet* newBullet = new Bullet(gameColors, bulletPosition, canon.getRotation());
		std::cout << newBullet->bulletShape.getPosition().x << ", " << newBullet->bulletShape.getPosition().y << "\n";
		magasin.push_back(newBullet);
	}
}

bool Player::WaitBeforeShoot() {
	if (timerForShoot.getElapsedTime().asSeconds() >= 1) {
		timerForShoot.restart();
		return true;
	}
	else {
		return false;
	}
}