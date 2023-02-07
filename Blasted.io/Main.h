#ifndef MAIN_H
#define MAIN_H
#include <SFML/Graphics.hpp>
#include <random>

#include "Menu.h"
#include "Player.h"
#include "Map.h"
#include "GameWindow.h"
#include "Colors.h"
#include "GameFont.h"
#include "GameState.h"
#include "Camera.h"

using namespace sf;
using namespace std;
class Game {
public: 
	GameWindow gameWindow;
	Player player;
	Map currentMap;
	GameFont gameFont;
	Menu menu;
	GameColors gameColors;
	Camera gameCamera;

	GameState currentGameState;

	void InitGame();
};

	int main();


#endif