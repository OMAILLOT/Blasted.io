#include <SFML/Graphics.hpp>
#include "Colors.h"

Colors Colors::Init()
{
	this->darkGrey = Color(168, 168, 168);
	this->grey = Color(184, 184, 184);
	this->lightGrey = Color(205, 205, 205);

	this->blue = Color(0, 179, 223);

	return *this;
}
