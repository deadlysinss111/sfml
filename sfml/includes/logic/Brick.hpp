#pragma once
#include "GameObject.hpp"
#include <SFML/Graphics.hpp>


class Brick : GameObject {
public:
	int life;
	Brick();
	~Brick();
	sf::RectangleShape* rectangle;
};