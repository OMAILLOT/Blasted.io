#include "Camera.h"
#include "Player.h"
#include "Map.h"
#include "Tools.h"


GameCamera::GameCamera(GameWindow& win) {
	camera.setSize(sf::Vector2f(win.WIN_WIDTH, win.WIN_HEIGHT));

	//camera.setCenter(Vector2f(0, 0));
	win.window.setView(camera);
}

void GameCamera::LerpCamera(Player& player, GameWindow& win)
{
	sf::Vector2f cameraPos = camera.getCenter();
	sf::Vector2f playerPos = player.playerRenderer.getPosition();

	playerPos.x += player.playerRenderer.getRadius();
	playerPos.y += player.playerRenderer.getRadius();


	cameraPos = sf::Vector2f(tools::Lerp(cameraPos, playerPos, 0.05f));

	camera.setCenter(cameraPos);
	win.window.setView(camera);


}


