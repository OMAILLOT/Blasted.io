#pragma once
#include "SFML/Graphics.hpp"
class Camera
{
	public: 
		sf::View camera;
		void LerpCamera();
		Camera();
	
};

