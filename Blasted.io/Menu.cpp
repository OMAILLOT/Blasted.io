#include "Menu.h"
#include "Map.h"
#include <iostream>
#include <random>

void Menu::DrawMenu(GameWindow& win)
{
	win.window.draw(titleText);
	win.window.draw(playText);
	win.window.draw(settingText);
	win.window.draw(quitText);

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

Menu::Menu(GameFont& gameFont, GameWindow& win)
{
	win.window.draw(titleText);
	win.window.draw(playText);
	win.window.draw(settingText);
	win.window.draw(quitText);

	titleText.setFont(gameFont.font);
	titleText.setCharacterSize(72);
	titleText.setString("BLASTED.IO");
	titleText.setPosition(sf::Vector2f((win.WIN_WIDTH - titleText.getLocalBounds().width) / 2, 100));

	playText.setFont(gameFont.font);
	playText.setCharacterSize(36);
	playText.setString("PLAY");
	playText.setPosition(sf::Vector2f((win.WIN_WIDTH - playText.getLocalBounds().width) / 2, 300));

	settingText.setFont(gameFont.font);
	settingText.setCharacterSize(36);
	settingText.setString("SETTING");
	settingText.setPosition(sf::Vector2f((win.WIN_WIDTH - settingText.getLocalBounds().width) / 2, 370));

	quitText.setFont(gameFont.font);
	quitText.setCharacterSize(36);
	quitText.setString("QUIT");
	quitText.setPosition(sf::Vector2f((win.WIN_WIDTH - quitText.getLocalBounds().width) / 2, 440));
}

void Menu::HandleMenuInput(sf::Event& event, Player& player, GameState& gameState, GameWindow& win)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (!startGameKeyPressed)
		{
			startGameKeyPressed = true;

			if (event.key.code == sf::Keyboard::Up)
			{
				if (selectedItem > 0)
					selectedItem--;
			}
			else if (event.key.code == sf::Keyboard::Down)
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

	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Return)
		{
			if (selectedItem == 0)
			{
				mt19937 gen(random_device{}());

				int minX = (WorldCell.getLocalBounds().width * rows) / -2;
				int maxX = (WorldCell.getLocalBounds().width * rows) / 2;
				uniform_int_distribution<int> tempX(minX, maxX);

				int X = tempX(gen);

				int minY = ((WorldCell.getLocalBounds().height * columns) - player.playerRenderer.getRadius()) / -2;
				int maxY = ((WorldCell.getLocalBounds().height * columns) - player.playerRenderer.getRadius()) / 2;
				uniform_int_distribution<int> tempY(minY, maxY);

				int Y = tempY(gen);

				player.playerRenderer.setPosition(X, Y);
				player.canon.setPosition(X + player.playerRenderer.getRadius() - (player.canon.getLocalBounds().width - player.canon.getOutlineThickness() * 2) / 2, Y + player.playerRenderer.getRadius());

				gameState = GameState::Game;
			}
			else if (selectedItem == 1)
			{
				gameState = GameState::Setting;
			}
			else if (selectedItem == 2)
			{
				win.window.close();
			}
		}
	}
}
