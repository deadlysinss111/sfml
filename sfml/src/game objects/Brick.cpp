#define NOMINMAX
#include <windows.h>
#include "../../includes/logic/Brick.hpp"
#include <iostream>

Brick::Brick(InputManager* inputManager, sf::RenderWindow* window, int x, int y, int hp) : GameObject(inputManager, window, 10 +101 * x , 10 + 31 * y, 100, 30) {
	this->hp = hp;
}


Brick::~Brick() {};

bool Brick::update(float deltaT, std::vector<GameObject*>* objectVector){
	return 0;
}

void Brick::onHit() {
	this->hp -= 1;
	if (hp == 0) {
		this->dead = true;
	}
}