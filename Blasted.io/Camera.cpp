#include "Camera.h"
#include "Player.h"
#include "Map.h"
#include "Main.h"
#include "Tools.h"


void Camera::LerpCamera()
{
	Vector2f cameraPos = camera.getCenter();
	Vector2f playerPos = player->playerRenderer.getPosition();

	playerPos.x += player->playerRenderer.getRadius();
	playerPos.y += player->playerRenderer.getRadius();


	cameraPos = Vector2f(tools::Lerp(cameraPos, playerPos, 0.05f));

	camera.setCenter(cameraPos);
	gameWindow->window.setView(camera);


}

Camera::Camera() {
	Vector2f cameraPos = camera.getCenter();


	cameraPos = Vector2f(0,0);

	camera.setCenter(cameraPos);
	gameWindow->window.setView(camera);
}

