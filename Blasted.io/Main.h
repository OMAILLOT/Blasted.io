#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>


#include "input.h"

using namespace sf;
using namespace std;

//Const
const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

const int PLAYER_SPEED = 2;
Vector2f playerSpeed(0.f, 0.f);

const long rows = 32;
const long columns = 32;

const int squareSize = 48;
const float squareOutlineThickness = 1.f;


const Color darkGrey(168, 168, 168);
const Color grey(184, 184, 184);
const Color lightGrey(205, 205, 205);

const Color blue(0, 179, 223);



int main();
void HandleMenuInput(sf::Event& event);
void DrawMenu();
void DrawWorld();
void InitMenu();
void PlayerMovement();
void LerpCamera();
void InitWindow();
void InitPlayer();
void InitWorld();
void LoadFont();
void CheckInput();
void SetText(Text& txt, String str, int size);
Vector2f lerp(Vector2f start, Vector2f end, float percent);
Vector2f normalize(Vector2f vector);
void debug(const string& message);