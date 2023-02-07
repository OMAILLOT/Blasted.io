#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Colors.h"

//#include "Main.cpp"

using namespace sf;
using namespace std;

extern const long columns;
extern const long rows;

extern Sprite WorldCell;
extern Texture CellTexture;
extern RectangleShape backgroundWorld;

class Map {
public:
	void DrawWorld(GameWindow& gameWindow);
	Map(GameColors& gameColors);
};


#endif