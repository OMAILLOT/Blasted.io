#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "input.h"
//#include "Main.h"

using namespace sf;
using namespace std;

class Player {

public:
	Input* playerInput;
	CircleShape playerRenderer;
	Vector2f playerSpeed;
	const int PLAYER_SPEED = 2;
	View camera;


	Player();
	void PlayerMovement();
	Vector2f normalize(Vector2f vector);
	void CheckInput();
	void LerpCamera();
	Vector2f lerp(Vector2f start, Vector2f end, float percent);
};

#endif
