#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "input.h"
//#include "Main.h"

using namespace sf;
using namespace std;


extern const int PLAYER_SPEED = 2;

class Player {

public:
	Input* playerInput;
	CircleShape playerRenderer;
	Vector2f playerSpeed;


	Player();
	void PlayerMovement();
	Vector2f normalize(Vector2f vector);
	void CheckInput();
};

#endif
