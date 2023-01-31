#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Sprite WorldCell;
Texture CellTexture;
RectangleShape backgroundWorld;

const long rows = 32;
const long columns = 32;

const int squareSize = 48;
const float squareOutlineThickness = 1.f;


class Map {
public:
	void DrawWorld();
	void InitWorld();
};