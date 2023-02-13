#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "input.h"
#include "Colors.h"
#include "GameState.h"
#include "Bullet.h"

//#include "Main.h"
class GameWindow;
using namespace std;

class Player {

public:
	Input playerInput;
	sf::RectangleShape canon;
	sf::CircleShape playerRenderer;
	sf::Vector2f playerSpeed;
	vector<Bullet*> magasin;

	const int PLAYER_SPEED = 2;


	Player();
	~Player();
	void InitPlayer(GameColors& gameColors);
	void PlayerLoop(GameState& gameState, GameWindow& window);
	void PlayerMovement();
	void CheckInput(GameState& gameState);
	void RotateCanon(GameWindow& window);
	void InitPlayerPosition(float x, float y);

};

#endif
