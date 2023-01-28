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

int selectedItem = 0;
bool startGameKeyPressed = false;


enum class GameState { Menu, Game, Setting };

GameState state = GameState::Menu;

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

	Text titleText;
	titleText.setFont(font);
	titleText.setCharacterSize(72);
	titleText.setString("BLASTED.IO");
	titleText.setPosition(Vector2f((WIN_WIDTH - titleText.getLocalBounds().width) / 2, 100));

	Text playText;
	playText.setFont(font);
	playText.setCharacterSize(36);
	playText.setString("PLAY");
	playText.setPosition(Vector2f((WIN_WIDTH - playText.getLocalBounds().width) / 2, 300));

	Text settingText;
	settingText.setFont(font);
	settingText.setCharacterSize(36);
	settingText.setString("SETTING");
	settingText.setPosition(Vector2f((WIN_WIDTH - settingText.getLocalBounds().width) / 2, 370));

	Text quitText;
	quitText.setFont(font);
	quitText.setCharacterSize(36);
	quitText.setString("QUIT");
	quitText.setPosition(Vector2f((WIN_WIDTH - quitText.getLocalBounds().width) / 2, 440));


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) input.InputHandler(event, window);

		window.clear();

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				WorldCell.setPosition(i * WorldCell.getLocalBounds().width, j * WorldCell.getLocalBounds().height);
				WorldCell.move(-rows / 2 * WorldCell.getLocalBounds().width, -columns / 2 * WorldCell.getLocalBounds().height);
				window.draw(WorldCell);
			}
		}

		//cout << to_string((int)player.getPosition().x) << endl;


		if (state == GameState::Menu)
		{
			camera.setCenter(WIN_WIDTH / 2, WIN_HEIGHT / 2);
			window.setView(camera);

			if (event.type == Event::KeyPressed)
			{
				if (!startGameKeyPressed)
				{
					startGameKeyPressed = true;

					if (event.key.code == Keyboard::Up)
					{
						if (selectedItem > 0)
							selectedItem--;
					}
					else if (event.key.code == Keyboard::Down)
					{
						if (selectedItem < 2)
							selectedItem++;
					}

				}
			}
			else
			{
				startGameKeyPressed = false;
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Return)
				{
					if (selectedItem == 0)
					{
						mt19937 gen(random_device{}());

						int minX = (WorldCell.getLocalBounds().width * rows) / -2;
						int maxX = (WorldCell.getLocalBounds().width * rows) / 2;
						uniform_int_distribution<int> tempX(minX, maxX);

						int X = tempX(gen);

						int minY = ((WorldCell.getLocalBounds().height * columns) - player.getRadius()) / -2;
						int maxY = ((WorldCell.getLocalBounds().height * columns) - player.getRadius()) / 2;
						uniform_int_distribution<int> tempY(minY, maxY);

						int Y = tempY(gen);

						player.setPosition(X, Y);

						state = GameState::Game;
					}
					else if (selectedItem == 1)
					{
						state = GameState::Setting;
					}
					else if (selectedItem == 2)
					{
						window.close();
					}
				}
			}

			// Draw the menu items
			window.draw(titleText);
			window.draw(playText);
			window.draw(settingText);
			window.draw(quitText);

			// Highlight the selected menu item
			if (selectedItem == 0)
				playText.setFillColor(Color::Red);
			else
				playText.setFillColor(Color::White);

			if (selectedItem == 1)
				settingText.setFillColor(Color::Red);
			else
				settingText.setFillColor(Color::White);

			if (selectedItem == 2)
				quitText.setFillColor(Color::Red);
			else
				quitText.setFillColor(Color::White);

		}
		else if (state == GameState::Game)
		{
			//GameLoop

			CheckInput();
			PlayerMovement();

			LerpCamera();

			//window.draw(backgroundWorld);

			window.draw(player);
		}
		else if (state == GameState::Setting)
		{
			// Settings

		}



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
	if (input.GetButton().exit == true)
	{
		state = GameState::Menu;
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


void debug(const string& message)
{
	cout << message << endl;
}

#pragma endregion


