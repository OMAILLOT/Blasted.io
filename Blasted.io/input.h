#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Input
{
	struct Button { bool left, right, up, down, attack; };

public:
	Input();

	Button GetButton(void) const;

	void InputHandler(sf::Event& event, sf::RenderWindow& window);


private:
	Button btn;
};

