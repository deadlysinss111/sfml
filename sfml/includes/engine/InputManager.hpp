#pragma once
#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <functional>


class InputManager {
public:
	InputManager(sf::RenderWindow* window);
	~InputManager();

	sf::RenderWindow* window;
	
	void keyMapping(sf::Keyboard::Key, void(*)());
	void mouseMapping(sf::Mouse::Button, void(*)());
	void moveMapping(std::function<void()>);

	void manage();
private:
	std::unordered_map<sf::Keyboard::Key, void(*)()> keyMap;
	std::unordered_map<sf::Mouse::Button, void(*)()> mouseMap;
	std::vector<std::function<void()>> moveEffect;
};