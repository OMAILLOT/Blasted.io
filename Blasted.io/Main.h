#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"

using namespace sf;
using namespace std;

//Const
const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

const int PLAYER_SPEED = 5;

const long rows = 64;
const long columns = 64;

const int squareSize = 48;
const float squareOutlineThickness = 1.f;


const Color darkGrey(168, 168, 168);
const Color grey(184,184, 184);
const Color lightGrey(205, 205, 205);

const Color blue(0, 179, 223);



int main();

void InitWindow();

void InitPlayer();

void InitWorld();

void LoadFont();
void CheckInput();
void SetText(Text& txt, String str, int size);