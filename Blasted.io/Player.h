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
	int lifePoint = 3;
	int originalLifePoint;

	float speedIncrease;

	Input playerInput;
	sf::RectangleShape canon;
	sf::CircleShape playerRenderer;
	sf::Vector2f playerSpeed;
	const int PLAYER_SPEED = 2;

	vector<Bullet*> magasin;
	sf::Clock timerForShoot;
	float delayOnShoot;

	float increaseBulletSpeed;
	int ennemiesDestroyBeforeLevelUp;
	int baseEnnemiesDestroyBeforeLevelUp;
	int numberOfLevelUp;

	Player();
	~Player();

	void InitPlayer(GameColors& gameColors);
	void PlayerLoop(GameState& gameState, GameWindow& window);
	void PlayerMovement();
	void CheckInput(GameState& gameState);
	void RotateCanon(GameWindow& window);
	void InitPlayerPosition(float x, float y);
	void Shoot();
	void UpdatePlayerLife(GameState& gameState);
	void ennemisDestroy();
};

#endif
