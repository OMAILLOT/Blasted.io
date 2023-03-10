#include "GameWindow.h"
#include "Camera.h"

GameWindow::GameWindow()
{
	window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	sf::ContextSettings options;
	options.antialiasingLevel = 8;
}

void GameWindow::InitPlayerOnWindow(GameCamera& gameCamera, Player& player) {
	gameCamera.camera.setSize(sf::Vector2f(WIN_WIDTH, WIN_HEIGHT));
	gameCamera.camera.setCenter(player.playerRenderer.getPosition());
}
