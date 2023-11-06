#pragma once
#include "GameObject.hpp"
#include <SFML/Graphics.hpp>


class Brick : GameObject {
public:
	Brick();
	~Brick();
	sf::RectangleShape* rectangle;
	void life();
};