#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Camera.h"
#include "Player.h"


class GameWindow
{
public:
	const int WIN_WIDTH = 1280;
	const int WIN_HEIGHT = 720;

	sf::RenderWindow window;

	GameWindow();
	void InitPlayerOnWindow(Camera& gameCamera, Player& player);
};

