#include "input.h"

Input::Input() {
	btn.left = btn.right = btn.up = btn.down = btn.attack = false;
}

Input::Button Input::GetButton(void) const
{
	return btn;
}

void Input::InputHandler(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::Closed) window.close();

	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Left:
			btn.left = true;
			break;
		case sf::Keyboard::Right:
			btn.right = true;
			break;
		case sf::Keyboard::Down:
			btn.down = true;
			break;
		case sf::Keyboard::Up:
			btn.up = true;
			break;
		case sf::Keyboard::Escape:
			btn.exit = true;
			break;
		default:
			break;
		}
	}
	if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Left:
			btn.left = false;
			break;
		case sf::Keyboard::Right:
			btn.right = false;
			break;
		case sf::Keyboard::Down:
			btn.down = false;
			break;
		case sf::Keyboard::Up:
			btn.up = false;
			break;
		case sf::Keyboard::Escape:
			btn.exit = false;
			break;
		default:
			break;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			btn.attack = true;
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			btn.attack = false;
		}
	}
}