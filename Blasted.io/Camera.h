#pragma once
#include "SFML/Graphics.hpp"
#include "GameWindow.h"
#include "Player.h"

class GameCamera
{
	public: 
		sf::View camera;
		GameCamera(GameWindow& win);
		void LerpCamera(Player& player, GameWindow& win);

	
};

