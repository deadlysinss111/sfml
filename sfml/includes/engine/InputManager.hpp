#pragma once
#include "SFML/Graphics.hpp"
#include <unordered_map>


class InputManager {
public:
	InputManager(sf::RenderWindow* window);
	~InputManager();

	sf::RenderWindow* window;
	std::unordered_map<sf::Keyboard::Key, void*> eventMap;

	void manage();
	/*void bindMap(sf::Event* event, void(*function)());*/
};