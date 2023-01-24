#include <SFML/Graphics.hpp>
#include <iostream>
#include "input.h"

using namespace sf;
using namespace std;

//Const
const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

const int WORLD_WIDTH = 10000;
const int WORLD_HEIGHT = 10000;

int main();

void LoadFont();
void CheckBtn();
void SetText(Text& txt, String str, int size);