#include "GameFont.h"
#include <iostream>



GameFont::GameFont()
{
	if (!font.loadFromFile("res/poppins.ttf")) {
		std::cout << "Erreur de chargement de font" << std::endl;
	}
}

void GameFont::SetText(sf::Text& txt, sf::String str, int size)
{
	//Je sais que cette fonction étais créer mais je ne l'ai vue appeler nul part
}
