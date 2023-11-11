#pragma once
#include "GameObject.hpp"

class RectangleShape;
class Cannon : public GameObject {
public:
	Cannon(InputManager* inputManager, int x, int y, float width, float height);
	~Cannon();
	
	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void display(sf::RenderWindow* window);
	void rotate();
};
