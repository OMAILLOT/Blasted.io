#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Input
{
	struct Button { bool left, right, up, down, attack, exit; };

public:
	Input();

	Button GetButton(void) const;

	void InputHandler(Event& event, RenderWindow& window);


private:
	Button btn;
};

#endif

