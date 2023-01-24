#include "Main.h"

//Variable global
RenderWindow window;
View camera;
Input input;
Font font;
CircleShape player;
RectangleShape backgroundWorld;
vector<RectangleShape> world;

float posX, posY = 0;

int main()
{
	//Window
	InitWindow();

	//Player
	InitPlayer();

	//Map
	InitWorld();

	//Other
	LoadFont();


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) input.InputHandler(event, window);
		
		CheckInput();

		player.setPosition(posX, posY);

		camera.setCenter(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
		window.setView(camera);

		window.clear();

		window.draw(backgroundWorld);
		for (auto& square : world) window.draw(square);
	
		window.draw(player);

		window.display();
	}

	return 0;
}

void InitWindow()
{
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	camera.setSize(Vector2f(WIN_WIDTH, WIN_HEIGHT));
	camera.setCenter(player.getPosition());

	ContextSettings options;
	options.antialiasingLevel = 8;
}

void InitPlayer()
{
	player.setRadius(25.f);
	player.setFillColor(blue);

	posX = -player.getRadius(), posY = -player.getRadius();
}

void InitWorld()
{
	backgroundWorld.setSize(Vector2f(rows * squareSize * 2, columns * squareSize * 2));
	backgroundWorld.setPosition(Vector2f(-rows * squareSize * 2 / 2, -columns * squareSize * 2 / 2));
	backgroundWorld.setFillColor(darkGrey);

	Vector2f centeredGridPosition(-(rows * squareSize / 2), -(columns * squareSize / 2));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			RectangleShape square;
			square.setSize(Vector2f(squareSize, squareSize));
			square.setPosition(i * squareSize, j * squareSize);
			square.setFillColor(lightGrey);
			square.setOutlineColor(grey);

			square.setOutlineThickness(squareOutlineThickness);
			square.move(centeredGridPosition);

			world.push_back(square);
		}
	}
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

void CheckInput() {
	if (input.GetButton().left == true)
	{
		posX -= PLAYER_SPEED;

		if (posX < -(rows * squareSize / 2))
			posX = -(rows * squareSize / 2);
	}
	if (input.GetButton().right == true)
	{
		posX += PLAYER_SPEED;

		if (posX > (rows * squareSize / 2) - player.getRadius() * 2)
			posX = (rows * squareSize / 2) - player.getRadius() * 2;
	}
	if (input.GetButton().up == true)
	{
		posY -= PLAYER_SPEED;

		if (posY < -(columns * squareSize / 2))
			posY = -(columns * squareSize / 2);

	}
	if (input.GetButton().down == true)
	{
		posY += PLAYER_SPEED;

		if (posY > (columns * squareSize / 2) - player.getRadius() * 2)
			posY = (columns * squareSize / 2) - player.getRadius() * 2;
	}
	if (input.GetButton().attack == true)
	{
	}
}