#include "GameWindow.h"
#include "Main.h"

GameWindow::GameWindow()
{
	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	player->camera.setSize(Vector2f(WIN_WIDTH, WIN_HEIGHT));
	player->camera.setCenter(player->playerRenderer.getPosition());

	ContextSettings options;
	options.antialiasingLevel = 8;
}
