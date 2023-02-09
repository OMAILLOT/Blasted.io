#include "Player.h"
#include "Map.h"


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


