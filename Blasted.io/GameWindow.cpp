#include "GameWindow.h"
#include "Main.h"

GameWindow::GameWindow()
{
	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	ContextSettings options;
	options.antialiasingLevel = 8;
}

void GameWindow::InitPlayerOnWindow() {
	gameCamera->camera.setSize(Vector2f(WIN_WIDTH, WIN_HEIGHT));
	gameCamera->camera.setCenter(player->playerRenderer.getPosition());
}
