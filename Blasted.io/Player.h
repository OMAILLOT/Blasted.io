#pragma once
#include <SFML/Graphics.hpp>
#include "input.h"

using namespace sf;
using namespace std;

class Player {

	const int PLAYER_SPEED = 2;
	Vector2f normalize(Vector2f vector);

public:
	Input* playerInput;
	CircleShape playerRenderer;
	Vector2f playerSpeed;


	Player();
	void PlayerMovement();
	void CheckInput();
};
