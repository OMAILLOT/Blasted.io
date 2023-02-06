#include <iostream>
#include "Main.h"

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;


GameState currentGameState;
GameWindow* gameWindow;
Player* player;
Map* currentMap;
GameFont* gameFont;
Menu* menu;
GameColors* gameColors;
Camera* gameCamera;
int main()
{
	InitGame();

	while (gameWindow->window.isOpen())
	{
		Event event;
		while (gameWindow->window.pollEvent(event)) player->playerInput->InputHandler(event, gameWindow->window);

		gameWindow->window.clear();

		currentMap->DrawWorld();

		if (currentGameState == GameState::Menu)
		{

			menu->HandleMenuInput(event);

			menu->DrawMenu();

		}
		else if (currentGameState == GameState::Game)
		{
			//GameLoop
			gameWindow->InitPlayerOnWindow();

			player->CheckInput();

			player->PlayerMovement();

			gameCamera->LerpCamera();

			gameWindow->window.draw(player->playerRenderer);
		}
		else if (currentGameState == GameState::Setting)
		{
			// Settings

		}

		gameWindow->window.display();
	}

	return 0;
}

void InitGame() {
	currentGameState = GameState::Menu;
	gameColors = new GameColors();
	player = new Player();
	gameWindow = new GameWindow();
	gameCamera = new Camera();
	currentMap = new Map();
	gameFont = new GameFont();
	gameFont->LoadFont();
	menu = new Menu();
}


