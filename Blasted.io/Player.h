#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Player {

	const int PLAYER_SPEED = 2;
	Vector2f normalize(Vector2f vector);
	Input input;

public:
	CircleShape playerRenderer;
	Vector2f playerSpeed;


	Player(Input input);
	void PlayerMovement();
	void CheckInput();
};
