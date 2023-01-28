#include "input.h"

Input::Input() {
	btn.left = btn.right = btn.up = btn.down = btn.attack = false;
}

Input::Button Input::GetButton(void) const
{
	return btn;
}

void Input::InputHandler(Event& event, RenderWindow& window)
{
	if (event.type == Event::Closed) window.close();

	if (event.type == Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Left:
			btn.left = true;
			break;
		case Keyboard::Right:
			btn.right = true;
			break;
		case Keyboard::Down:
			btn.down = true;
			break;
		case Keyboard::Up:
			btn.up = true;
			break;
		case Keyboard::Escape:
			btn.exit = true;
			break;
		default:
			break;
		}
	}
	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Left:
			btn.left = false;
			break;
		case Keyboard::Right:
			btn.right = false;
			break;
		case Keyboard::Down:
			btn.down = false;
			break;
		case Keyboard::Up:
			btn.up = false;
			break;
		case Keyboard::Escape:
			btn.exit = false;
			break;
		default:
			break;
		}
	}

	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			btn.attack = true;
		}
	}
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			btn.attack = false;
		}
	}
}