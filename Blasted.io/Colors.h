#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

struct GameColors {
	sf::Color darkGrey{ sf::Color(168, 168, 168) };
	sf::Color grey{ sf::Color(184, 184, 184) };
	sf::Color lightGrey{ sf::Color(205, 205, 205) };

	sf::Color PlayerColor { sf::Color(0, 179, 223) };
	sf::Color playerOutline{ sf::Color(0,133,168) };

	vector<sf::Color> PlayerHitColors{
	sf::Color(241,78,84),
	sf::Color(251, 153, 51),
	sf::Color(255, 255, 51) };

	sf::Color canonColor{ sf::Color(153,153,153) };
	sf::Color canonColorOutline{ sf::Color(114,114,114) };

	sf::Color enemyColor{ sf::Color(241,78,84) };
	sf::Color enemyColorOutline{ sf::Color(83,83,83) };
};