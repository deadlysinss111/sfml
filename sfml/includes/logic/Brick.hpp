#pragma once
//#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class Brick : public GameObject {
public:
	Brick(InputManager* inputManager, sf::RenderWindow* window, int x, int y, int hp);
	~Brick();

	int hp;
	static std::map<int, sf::Color> colorMap;

	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void onHit(GameObject* target);
};