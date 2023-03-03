#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "GameWindow.h"
#include "Colors.h"

//#include "Main.cpp"

using namespace std;

extern const long columns;
extern const long rows;

extern sf::Sprite WorldCell;
extern sf::Texture CellTexture;
extern sf::RectangleShape backgroundWorld;

class Map {
public:
	void DrawWorld(GameWindow& gameWindow);
	Map(GameColors& gameColors);
};


#endif