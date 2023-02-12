#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>

using namespace std;

class Input
{
	struct Button { bool left, right, up, down, attack, exit; };

public:
	Input();

	Button GetButton(void) const;

	void InputHandler(sf::Event& event, sf::RenderWindow& window);


public:
	Button btn;
};

#endif

