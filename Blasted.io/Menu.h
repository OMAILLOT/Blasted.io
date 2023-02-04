#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GameFont.h"



class Menu
{

public:
	GameFont* gameFont;
	
	sf::Text titleText;
	sf::Text playText;
	sf::Text settingText;
	sf::Text quitText;

	int selectedItem = 0;
	bool startGameKeyPressed = false;

	void DrawMenu();
	Menu();
	void HandleMenuInput(sf::Event& event);
};

