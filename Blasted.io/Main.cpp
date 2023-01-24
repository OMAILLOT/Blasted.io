#include "Main.h"

//Variable global
RenderWindow window;
View view;
Input input;
Font font;
CircleShape shape;

int posX, posY = 1;

int main()
{
	//Window
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	view.setSize(Vector2f(WIN_WIDTH, WIN_HEIGHT));
	view.setCenter(shape.getPosition());


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
	//if (!font.loadFromFile("res/poppins.ttf")) {
	//	cout << "Erreur de chargement de font" << endl;
	//}
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
		view.move(-10, 0);

		posX -= 10;

		if (posX < 0)
			posX = 0;
	}
	if (input.GetButton().right == true)
	{
		view.move(10, 0);

		posX += 10;

		if (posX > WIN_WIDTH - shape.getRadius() * 2)
			posX = WIN_WIDTH - shape.getRadius() * 2;
	}
	if (input.GetButton().up == true)
	{
		view.move(0, -10);

		posY -= 10;

		if (posY < 0)
			posY = 0;

	}
	if (input.GetButton().down == true)
	{
		view.move(0, 10);

		posY += 10;

		if (posY > WIN_HEIGHT - shape.getRadius() * 2)
			posY = WIN_HEIGHT - shape.getRadius() * 2;
	}
	if (input.GetButton().attack == true)
	{
	}
}