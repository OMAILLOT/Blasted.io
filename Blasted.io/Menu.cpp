#include "Menu.h"
#include "Main.h"
#include "Map.h"
#include <iostream>

void Menu::DrawMenu()
{
	gameWindow->window.draw(titleText);
	gameWindow->window.draw(playText);
	gameWindow->window.draw(settingText);
	gameWindow->window.draw(quitText);

	if (selectedItem == 0)
		playText.setFillColor(sf::Color::Red);
	else
		playText.setFillColor(sf::Color::White);

	if (selectedItem == 1)
		settingText.setFillColor(sf::Color::Red);
	else
		settingText.setFillColor(sf::Color::White);

	if (selectedItem == 2)
		quitText.setFillColor(sf::Color::Red);
	else
		quitText.setFillColor(sf::Color::White);
}

Menu::Menu()
{
	
	titleText.setFont(gameFont->font);
	titleText.setCharacterSize(72);
	titleText.setString("BLASTED.IO");
	//titleText.setPosition(Vector2f((gameWindow->WIN_WIDTH - titleText.getLocalBounds().width) / 2, 100));
	titleText.setPosition(Vector2f(0,0));

	playText.setFont(gameFont->font);
	playText.setCharacterSize(36);
	playText.setString("PLAY");
	playText.setPosition(Vector2f((gameWindow->WIN_WIDTH - playText.getLocalBounds().width) / 2, 300));

	settingText.setFont(gameFont->font);
	settingText.setCharacterSize(36);
	settingText.setString("SETTING");
	settingText.setPosition(Vector2f((gameWindow->WIN_WIDTH - settingText.getLocalBounds().width) / 2, 370));

	quitText.setFont(gameFont->font);
	quitText.setCharacterSize(36);
	quitText.setString("QUIT");
	quitText.setPosition(Vector2f((gameWindow->WIN_WIDTH - quitText.getLocalBounds().width) / 2, 440));

}

void Menu::HandleMenuInput(sf::Event& event)
{
	if (event.type == Event::KeyPressed)
	{
		if (!startGameKeyPressed)
		{
			startGameKeyPressed = true;

			if (event.key.code == Keyboard::Up)
			{
				if (selectedItem > 0)
					selectedItem--;
			}
			else if (event.key.code == Keyboard::Down)
			{
				if (selectedItem < 2)
					selectedItem++;
			}

		}
	}
	else
	{
		startGameKeyPressed = false;
	}

	if (event.type == Event::KeyReleased)
	{
		if (event.key.code == Keyboard::Return)
		{
			if (selectedItem == 0)
			{
				mt19937 gen(random_device{}());

				int minX = (WorldCell.getLocalBounds().width * rows) / -2;
				int maxX = (WorldCell.getLocalBounds().width * rows) / 2;
				uniform_int_distribution<int> tempX(minX, maxX);

				int X = tempX(gen);

				int minY = ((WorldCell.getLocalBounds().height * columns) - player->playerRenderer.getRadius()) / -2;
				int maxY = ((WorldCell.getLocalBounds().height * columns) - player->playerRenderer.getRadius()) / 2;
				uniform_int_distribution<int> tempY(minY, maxY);

				int Y = tempY(gen);

				player->playerRenderer.setPosition(X, Y);

				currentGameState = GameState::Game;
			}
			else if (selectedItem == 1)
			{
				currentGameState = GameState::Setting;
			}
			else if (selectedItem == 2)
			{
				gameWindow->window.close();
			}
		}
	}
}
