#ifndef MAIN_H
#define MAIN_H
#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;
using namespace std;


//Const
extern const int WIN_WIDTH = 1280;
extern const int WIN_HEIGHT = 720;

//Variable global
extern RenderWindow window;
extern View camera;
extern Font font;

extern vector<RectangleShape> world;
 
 //Colors colors;;
 


 //Menu
extern Text titleText;
extern Text playText;
extern Text settingText;
extern Text quitText;

extern int selectedItem = 0;
extern bool startGameKeyPressed = false;


enum class GameState { Menu, Game, Setting };

GameState state = GameState::Menu;

int main();
void HandleMenuInput(sf::Event& event);
void DrawMenu();
void InitMenu();
void LerpCamera();
void InitWindow();
void LoadFont();
void SetText(Text& txt, String str, int size);
Vector2f lerp(Vector2f start, Vector2f end, float percent);

void debug(const string& message);

#endif