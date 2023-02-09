#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "input.h"
#include "Colors.h"
#include "GameState.h"
//#include "Main.h"

using namespace std;

class Player {

public:
	Input playerInput;
	sf::RectangleShape canon;
	sf::CircleShape playerRenderer;
	sf::Vector2f playerSpeed;
	const int PLAYER_SPEED = 2;


	Player();
	~Player();
	void InitPlayer(GameColors& gameColors);
	void PlayerMovement();
	sf::Vector2f normalize(sf::Vector2f vector);
	void CheckInput(GameState& gameState);

};

#endif
