#include "Camera.h"
#include "Player.h"
#include "Map.h"
#include "Main.h"
#include "Tools.h"


void Camera::LerpCamera(Player& player, GameWindow& win)
{
	Vector2f cameraPos = camera.getCenter();
	Vector2f playerPos = player.playerRenderer.getPosition();

	playerPos.x += player.playerRenderer.getRadius();
	playerPos.y += player.playerRenderer.getRadius();


	cameraPos = Vector2f(tools::Lerp(cameraPos, playerPos, 0.05f));

	camera.setCenter(cameraPos);
	win.window.setView(camera);


}

Camera::Camera(GameWindow& win) {

	camera.setSize(Vector2f(win.WIN_WIDTH, win.WIN_HEIGHT));

	//camera.setCenter(Vector2f(0, 0));
	win.window.setView(camera);
}

