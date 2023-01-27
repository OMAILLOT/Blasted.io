#include "Main.h"

//Variable global
RenderWindow window;
View camera;
Input input;
Font font;
CircleShape player;
RectangleShape backgroundWorld;
vector<RectangleShape> world;
Sprite WorldCell;

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


	Texture texture;
	if (!texture.loadFromFile("res/AllGridpng.png"))
		return 1;

	WorldCell.setTexture(texture);
	WorldCell.setPosition(0, 0);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) input.InputHandler(event, window);

		CheckInput();
		PlayerMovement();

		LerpCamera();

		window.clear();

		//window.draw(backgroundWorld);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				WorldCell.setPosition(i * WorldCell.getLocalBounds().width, j * WorldCell.getLocalBounds().height);
				WorldCell.move(-rows / 2 * WorldCell.getLocalBounds().width, -columns / 2 * WorldCell.getLocalBounds().height);
				window.draw(WorldCell);
			}
		}

		window.draw(player);

		window.display();
	}

	return 0;
}

void LerpCamera()
{
	Vector2f cameraPos = camera.getCenter();
	Vector2f playerPos = player.getPosition();

	playerPos.x += player.getRadius();
	playerPos.y += player.getRadius();


	cameraPos = Vector2f(lerp(cameraPos, playerPos, 0.05f));

	camera.setCenter(cameraPos);
	window.setView(camera);
}

void CheckInput() {
	if (input.GetButton().left == true)
	{
		playerSpeed.x = -PLAYER_SPEED;

		if (player.getPosition().x < -(rows / 2 * WorldCell.getLocalBounds().width))
			playerSpeed.x = 0;
	}
	if (input.GetButton().right == true)
	{
		playerSpeed.x = PLAYER_SPEED;

		if (player.getPosition().x > (rows / 2 * WorldCell.getLocalBounds().width) - player.getRadius() * 2)
			playerSpeed.x = 0;
	}
	if (input.GetButton().up == true)
	{
		playerSpeed.y = -PLAYER_SPEED;

		if (player.getPosition().y < -(columns / 2 * WorldCell.getLocalBounds().height))
			playerSpeed.y = 0;

	}
	if (input.GetButton().down == true)
	{
		playerSpeed.y = PLAYER_SPEED;

		if (player.getPosition().y > (columns / 2 * WorldCell.getLocalBounds().height) - player.getRadius() * 2)
			playerSpeed.y = 0;
	}
	if (input.GetButton().attack == true)
	{
	}

	if (input.GetButton().left == false && input.GetButton().right == false) playerSpeed.x = 0;
	if (input.GetButton().up == false && input.GetButton().down == false) playerSpeed.y = 0;
}

#pragma region Init

void InitWindow()
{
	window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Blasted.io");
	window.setVerticalSyncEnabled(true);

	camera.setSize(Vector2f(WIN_WIDTH, WIN_HEIGHT));
	camera.setCenter(player.getPosition());

	ContextSettings options;
	options.antialiasingLevel = 8;
}



void InitWorld()
{
	backgroundWorld.setSize(Vector2f(rows * squareSize * 2, columns * squareSize * 2));
	backgroundWorld.setPosition(Vector2f(-rows * squareSize * 2 / 2, -columns * squareSize * 2 / 2));
	backgroundWorld.setFillColor(darkGrey);

}
#pragma endregion

#pragma region Player

void InitPlayer()
{
	player.setRadius(25.f);
	player.setFillColor(blue);

	posX = -player.getRadius(), posY = -player.getRadius();
}

void PlayerMovement()
{
	playerSpeed = normalize(playerSpeed);

	playerSpeed.x *= PLAYER_SPEED;
	playerSpeed.y *= PLAYER_SPEED;

	player.move(playerSpeed);
}

Vector2f normalize(Vector2f vector) {
	float length = sqrt((vector.x * vector.x) + (vector.y * vector.y));
	if (length != 0)
		return Vector2f(vector.x / length, vector.y / length);
	else
		return vector;
}

#pragma endregion

#pragma region Tools


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

Vector2f lerp(Vector2f start, Vector2f end, float percent)
{
	return start + (end - start) * percent;
}
#pragma endregion


