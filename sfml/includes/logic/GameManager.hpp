#pragma once
#include <SFML/Graphics.hpp>

class GameManager {
public:
	GameManager();
	~GameManager();

	void move(sf::CircleShape circle, int x, int y);
};