#define NOMINMAX
#include <windows.h>
#include "../../includes/logic/Brick.hpp"

Brick::Brick(InputManager* inputManager, int x, int y, float width, float height) {
	this->inputManager = inputManager;
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setFillColor(sf::Color::Green);
	this->x = GetSystemMetrics(SM_CXSCREEN) / 2 - this->w / 2;
	this->y = GetSystemMetrics(SM_CYSCREEN) - this->y;
	this->w = width;
	this->h = height;
	this->velocity = new sf::Vector2f(0.f, 0.f);
	this->shape->setOrigin(sf::Vector2f(w / 2, h / 2));
}


Brick::~Brick() {};