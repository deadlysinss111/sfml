#pragma once
//#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Brick : public GameObject {
public:
	Brick(InputManager* inputManager, sf::RenderWindow* window, int x, int y, float width, float height);
	~Brick();
	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	//sf::RectangleShape* shape;
	void onHit();

	int hp;
};