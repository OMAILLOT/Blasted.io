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


//Variable global
extern GameWindow* gameWindow;
extern Player* player;
extern Map* currentMap;
extern GameFont* gameFont;
extern Menu* menu;
extern GameColors* gameColors;
extern Camera* gameCamera;

extern GameState currentGameState;
//extern GameState currentGameState;


int main();
void InitGame();

#endif