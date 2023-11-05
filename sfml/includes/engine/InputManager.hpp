#include "SFML/Graphics.hpp"

class InputManager {
public:
	InputManager(sf::RenderWindow* window);
	~InputManager();

	sf::RenderWindow* window;

	void manage();
};