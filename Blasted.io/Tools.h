#pragma once
#include "SFML/Graphics.hpp"
namespace tools {

	sf::Vector2f Lerp(sf::Vector2f start, sf::Vector2f end, float percent);
	sf::Vector2f normalize(sf::Vector2f vector);
	bool IsDelayIsExceeded(sf::Clock& currentClock, float delay);
}
