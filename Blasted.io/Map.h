#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
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
	void DrawWorld();
	Map();
};


#endif