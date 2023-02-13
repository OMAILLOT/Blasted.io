#include <iostream>
#include "Main.h"
#include "Menu.h"
#include "Player.h"
#include "Map.h"
#include "GameWindow.h"
#include "Colors.h"
#include "GameFont.h"
#include "GameState.h"
#include "Camera.h"

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

Game g;

int main()
{	
	g.InitGame();

}

void Game::InitGame()
{
	GameWindow gameWindow;
	GameColors gameColors;
	Player player;
	player.InitPlayer(gameColors);
	Map currentMap(gameColors);
	GameFont gameFont;
	gameFont.LoadFont();
	Menu menu(gameFont, gameWindow);

	GameCamera gameCamera(gameWindow);

	GameState currentGameState = GameState::Menu;


	
	while (gameWindow.window.isOpen())
	{
		sf::Event event;
		while (gameWindow.window.pollEvent(event)) player.playerInput.InputHandler(event, gameWindow.window);

		gameWindow.window.clear();

		currentMap.DrawWorld(gameWindow);

		if (currentGameState == GameState::Menu)
		{

			menu.HandleMenuInput(event,player,currentGameState,gameWindow);

			menu.DrawMenu(gameWindow);

		}
		else if (currentGameState == GameState::Game)
		{
			sf::Clock clock; // starts the clock
			//GameLoop
			//	sf::Time elapsed1 = clock.getElapsedTime();
			//std::cout << elapsed1.asSeconds() << std::endl;
			//	sf::Time elapsed2 = clock.getElapsedTime();
			//std::cout << elapsed2.asSeconds() << std::endl;

			player.PlayerLoop(currentGameState, gameWindow);

			gameCamera.LerpCamera(player,gameWindow);

			for (Bullet* bullet : player.magasin)
			{
				gameWindow.window.draw(bullet->bulletShape);
				bullet->BulletMoove();
			}
			gameWindow.window.draw(player.canon);
			gameWindow.window.draw(player.playerRenderer);
		}
		else if (currentGameState == GameState::Setting)
		{
			// Settings

		}

		gameWindow.window.display();
	}

	//return 0;
}
