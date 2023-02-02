#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
//#include "Main.cpp"

using namespace sf;
using namespace std;

extern Sprite WorldCell;
extern Texture CellTexture;
extern RectangleShape backgroundWorld;

extern const long rows = 32;
extern const long columns = 32;

extern const int squareSize = 48;
extern const float squareOutlineThickness = 1.f;


class Map {
public:
	void DrawWorld();
	void InitWorld();
};

#endif