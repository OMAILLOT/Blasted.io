#include "Main.h"

//Variable global
RenderWindow window;
View camera;
Input input;
Font font;
CircleShape player;
RectangleShape world,backgroundWorld;

float posX, posY = 1;

int main()
{
	//Window
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	camera.setSize(Vector2f(WIN_WIDTH, WIN_HEIGHT));
	camera.setCenter(player.getPosition());

	ContextSettings options;
	options.antialiasingLevel = 8;

	//Other
	LoadFont();

	player.setRadius(40.f);
	player.setFillColor(Color::Green);

	// Création de la carte carrée

	world.setSize(Vector2f(WORLD_WIDTH, WORLD_HEIGHT));
	world.setPosition(Vector2f(-WORLD_WIDTH / 2, -WORLD_HEIGHT / 2));
	world.setFillColor(Color::White);
	world.setOutlineColor(Color::Black);
	world.setOutlineThickness(10.f);

	backgroundWorld.setSize(Vector2f(WORLD_WIDTH * 2, WORLD_HEIGHT * 2));
	backgroundWorld.setPosition(Vector2f(-WORLD_WIDTH * 2 / 2, -WORLD_HEIGHT * 2 / 2));
	backgroundWorld.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			input.InputHandler(event, window);
		}

		CheckBtn();

		player.setPosition(posX, posY);

		camera.setCenter(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
		window.setView(camera);


		window.clear();

		window.draw(backgroundWorld);
		window.draw(world);
		window.draw(player);

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
		posX -= 10;

		if (posX < -WORLD_WIDTH / 2)
			posX = -WORLD_WIDTH / 2;
	}
	if (input.GetButton().right == true)
	{
		posX += 10;

		if (posX > (WORLD_WIDTH / 2) - player.getRadius() * 2)
			posX = (WORLD_WIDTH / 2) - player.getRadius() * 2;
	}
	if (input.GetButton().up == true)
	{
		posY -= 10;

		if (posY < -WORLD_HEIGHT / 2)
			posY = -WORLD_HEIGHT / 2;

	}
	if (input.GetButton().down == true)
	{
		posY += 10;

		if (posY > (WORLD_HEIGHT / 2) - player.getRadius() * 2)
			posY = (WORLD_HEIGHT / 2) - player.getRadius() * 2;
	}
	if (input.GetButton().attack == true)
	{
	}
}