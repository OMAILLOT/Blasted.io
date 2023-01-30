#pragma once
#include <SFML/Graphics>
const long rows = 32;
const long columns = 32;

const int squareSize = 48;
const float squareOutlineThickness = 1.f;


class Map {
	void DrawWorld();
	void InitWorld();
};