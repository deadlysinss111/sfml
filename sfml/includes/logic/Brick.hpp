#pragma once
//#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Brick : GameObject {
public:
	Brick(InputManager* inputManager, int x, int y, float width, float height);
	~Brick();
	//sf::RectangleShape* shape;

private:
	int hp;
};