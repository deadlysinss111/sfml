#define NOMINMAX
#include <windows.h>
#include "../../includes/logic/Brick.hpp"
#include <iostream>

Brick::Brick(InputManager* inputManager, sf::RenderWindow* window, int x, int y, float width, float height) {
	this->inputManager = inputManager;
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setFillColor(sf::Color::Green);
	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
	this->hp = 3;
	this->shape->setPosition(x, y);
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