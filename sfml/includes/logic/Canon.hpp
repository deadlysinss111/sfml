#pragma once
#include "GameObject.hpp"


class Canon : GameObject {
public:
	Canon(InputManager* inputManager, int x, int y, float width, float height);
	~Canon();
	void rotate();
	sf::RectangleShape* shape;
};