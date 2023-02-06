#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>


class GameFont
{
public:
	sf::Font font;

	void LoadFont();
	void SetText(sf::Text& txt, sf::String str, int size);
};

