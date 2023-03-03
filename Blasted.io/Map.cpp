#include <SFML/Graphics.hpp>
#include "Map.h"

sf::Sprite WorldCell;
sf::Texture CellTexture;
sf::RectangleShape backgroundWorld;

const long rows = 32;
const long columns = 32;

const int squareSize = 48;
const float squareOutlineThickness = 1.f;

void Map::DrawWorld(GameWindow& gameWindow)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			WorldCell.setPosition(i * WorldCell.getLocalBounds().width, j * WorldCell.getLocalBounds().height);
			WorldCell.move(-rows / 2 * WorldCell.getLocalBounds().width, -columns / 2 * WorldCell.getLocalBounds().height);
			gameWindow.window.draw(WorldCell);
		}
	}
}

Map::Map(GameColors& gameColors)
{
	if (!CellTexture.loadFromFile("res/AllGridpng.png"))
		return;

	WorldCell.setTexture(CellTexture);
	WorldCell.setPosition(0, 0);

	backgroundWorld.setSize(sf::Vector2f(rows * squareSize * 2, columns * squareSize * 2));
	backgroundWorld.setPosition(sf::Vector2f(-rows * squareSize * 2 / 2, -columns * squareSize * 2 / 2));
	backgroundWorld.setFillColor(gameColors.darkGrey);
}
