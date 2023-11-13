#pragma once
#include "GameObject.hpp"

class RectangleShape;
class Cannon : public GameObject {
public:
	Cannon(InputManager* inputManager, sf::RenderWindow* window);
	~Cannon();
	
	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void rotate();
};
