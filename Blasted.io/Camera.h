#pragma once
#include "SFML/Graphics.hpp"
class Camera
{
	public: 
		sf::View camera;
		void LerpCamera(Player& player, GameWindow& win);
		Camera(GameWindow& win);
	
};

