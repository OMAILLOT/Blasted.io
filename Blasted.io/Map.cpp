#include "Map.h"
#include <SFML/Graphics.hpp>

Sprite WorldCell;
Texture CellTexture;
RectangleShape backgroundWorld;


void Map::DrawWorld()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			WorldCell.setPosition(i * WorldCell.getLocalBounds().width, j * WorldCell.getLocalBounds().height);
			WorldCell.move(-rows / 2 * WorldCell.getLocalBounds().width, -columns / 2 * WorldCell.getLocalBounds().height);
			window.draw(WorldCell);
		}
	}
}

void Map::InitWorld()
{
	if (!CellTexture.loadFromFile("res/AllGridpng.png"))
		return;

	WorldCell.setTexture(CellTexture);
	WorldCell.setPosition(0, 0);

	backgroundWorld.setSize(Vector2f(rows * squareSize * 2, columns * squareSize * 2));
	backgroundWorld.setPosition(Vector2f(-rows * squareSize * 2 / 2, -columns * squareSize * 2 / 2));
	backgroundWorld.setFillColor(colors.darkGrey);
}