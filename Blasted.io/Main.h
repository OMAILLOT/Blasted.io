#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Colors.h"
#include "Player.h"
#include "input.h"
#include "Map.h"

using namespace sf;
using namespace std;



//Const
const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

//Variable global
RenderWindow window;
View camera;
Font font;

vector<RectangleShape> world;

Colors colors;
Input* playerInput;
Player* player;
Map* currentMap;

//Menu
Text titleText;
Text playText;
Text settingText;
Text quitText;

int selectedItem = 0;
bool startGameKeyPressed = false;


enum class GameState { Menu, Game, Setting };

GameState state = GameState::Menu;



int main();
void HandleMenuInput(sf::Event& event);
void DrawMenu();
void InitMenu();
void LerpCamera();
void InitWindow();
void LoadFont();
void SetText(Text& txt, String str, int size);
Vector2f lerp(Vector2f start, Vector2f end, float percent);

void debug(const string& message);