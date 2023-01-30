#include <SFML/Graphics.hpp>
#include <random>
#include "Colors.h"
#include "Player.h"

using namespace sf;
using namespace std;



//Const
const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;

const long rows = 32;
const long columns = 32;

const int squareSize = 48;
const float squareOutlineThickness = 1.f;



int main();
void HandleMenuInput(sf::Event& event);
void DrawMenu();
void DrawWorld();
void InitMenu();
void LerpCamera();
void InitWindow();
void InitWorld();
void LoadFont();
void SetText(Text& txt, String str, int size);
Vector2f lerp(Vector2f start, Vector2f end, float percent);

void debug(const string& message);