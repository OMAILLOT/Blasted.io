#pragma once
#include <SFML/Graphics/RenderWindow.hpp>


class GameWindow
{
public:
	const int WIN_WIDTH = 1280;
	const int WIN_HEIGHT = 720;

	sf::RenderWindow window;

	GameWindow();
};

