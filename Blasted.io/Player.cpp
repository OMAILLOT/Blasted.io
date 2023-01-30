#include "Player.h"
#include "input.h"



Player::Player(Input input_) {
	input = input_;
	playerRenderer.setRadius(25.f);
	playerRenderer.setFillColor(  Color::Blue);
}

void Player::PlayerMovement()
{

	playerSpeed = normalize(playerSpeed);

	playerSpeed.x *= PLAYER_SPEED;
	playerSpeed.y *= PLAYER_SPEED;

	playerRenderer.move(playerSpeed);

}

Vector2f Player::normalize(Vector2f vector) {
	float length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (length != 0)
		return Vector2f(vector.x / length, vector.y / length);
	else
		return vector;
	return Vector2f();
}

void Player::CheckInput() {
	if (input.GetButton().left == true)
	{
		playerSpeed.x = -PLAYER_SPEED;

		if (playerRenderer.getPosition().x < -(rows / 2 * WorldCell.getLocalBounds().width))
			playerSpeed.x = 0;
	}
	if (input.GetButton().right == true)
	{
		playerSpeed.x = PLAYER_SPEED;

		if (playerRenderer.getPosition().x > (rows / 2 * WorldCell.getLocalBounds().width) - playerRenderer.getRadius() * 2)
			playerSpeed.x = 0;
	}
	if (input.GetButton().up == true)
	{
		playerSpeed.y = -PLAYER_SPEED;

		if (playerRenderer.getPosition().y < -(columns / 2 * WorldCell.getLocalBounds().height))
			playerSpeed.y = 0;

	}
	if (input.GetButton().down == true)
	{
		playerSpeed.y = PLAYER_SPEED;

		if (playerRenderer.getPosition().y > (columns / 2 * WorldCell.getLocalBounds().height) - playerRenderer.getRadius() * 2)
			playerSpeed.y = 0;
	}
	if (input.GetButton().attack == true)
	{
	}
	if (input.GetButton().exit == true)
	{
		state = GameState::Menu;
	}

	if (input.GetButton().left == false && input.GetButton().right == false) playerSpeed.x = 0;
	if (input.GetButton().up == false && input.GetButton().down == false) playerSpeed.y = 0;
}


