#pragma once
#include "GameObject.hpp"

class RectangleShape;
class Cannon : public GameObject {
public:
	Cannon(InputManager* inputManager, int x, int y, float width, float height);
	~Cannon();
	//sf::RectangleShape* shape;

	void rotate();
};
