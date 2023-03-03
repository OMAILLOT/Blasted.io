#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GameFont.h"
#include "GameWindow.h"
#include "Player.h"

class Menu
{

public:

	sf::Text titleText;
	sf::Text playText;
	sf::Text settingText;
	sf::Text quitText;

	int selectedItem = 0;
	bool startGameKeyPressed = false;

	void DrawMenu(GameWindow& win);
	Menu(GameFont& gameFont, GameWindow& win);
	void HandleMenuInput(sf::Event& event, Player& player, GameState& gameState, GameWindow& win);
};

