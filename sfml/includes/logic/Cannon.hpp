#pragma once
#include "GameObject.hpp"
#include "../../includes/engine/InputManager.hpp"
#include "../../includes/logic/Maths.hpp"

class Cannon : public GameObject {
public:
	Cannon(InputManager* inputManager, sf::RenderWindow* window);
	~Cannon();
	
	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void rotate();
private:
	InputManager* inputManager;
};
