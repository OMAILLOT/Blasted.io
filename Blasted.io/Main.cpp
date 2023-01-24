#include "Main.h"

//Variable global
RenderWindow window;
Input input;
Font font;
CircleShape shape;

int posX, posY = 1;

int malin()
{
	//Window
	window.create(VideoMode(1280, 720, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	ContextSettings options;
	options.antialiasingLevel = 8;

	//Other
	LoadFont();

	shape.setRadius(100.f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			input.InputHandler(event, window);
		}

		CheckBtn();
		shape.setPosition(posX, posY);

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}


void LoadFont()
{
	if (!font.loadFromFile("res/poppins.ttf")) {
		cout << "Erreur de chargement de font" << endl;
	}
}

void SetText(Text& txt, String str, int size)
{
	txt.setFont(font);
	txt.setString(str);
	txt.setCharacterSize(size);
}

void CheckBtn() {
	if (input.GetButton().left == true)
	{
		posX -= 10;

		if (posX < 0)
			posX = 0;
	}
	if (input.GetButton().right == true)
	{
		posX += 10;

		if (posX > WIN_WIDTH - shape.getRadius() * 2)
			posX = WIN_WIDTH - shape.getRadius() * 2;
	}
	if (input.GetButton().up == true)
	{
		posY -= 10;

		if (posY < 0)
			posY = 0;

	}
	if (input.GetButton().down == true)
	{
		posY += 10;

		if (posY > WIN_HEIGHT - shape.getRadius() * 2)
			posY = WIN_HEIGHT - shape.getRadius() * 2;
	}
	if (input.GetButton().attack == true)
	{
	}
}