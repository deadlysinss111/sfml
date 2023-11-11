#pragma once
//#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Brick : GameObject {
public:
	Brick(InputManager* inputManager, int x, int y, float width, float height);
	~Brick();
	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	//sf::RectangleShape* shape;

private:
	int hp;
};