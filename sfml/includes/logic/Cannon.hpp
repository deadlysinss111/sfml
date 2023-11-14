#pragma once

#include "GameObject.hpp"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace sf
{
	class RenderWindow;
}

class InputManager;

class Cannon : public GameObject {
public:
	Cannon() {}
	//Cannon(InputManager* inputManager, sf::RenderWindow* window);
	~Cannon() {};
	
	void f() override;

	//bool update(float deltaT, std::vector<GameObject*>* objectVector) override;
	//void rotate();
private:
	//InputManager* inputManager;
};
