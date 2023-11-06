//#include <SFML/Graphics.hpp>
#include "../../includes/logic/GameObject.hpp"

GameObject::GameObject(int x, int y, float radius) {
	this->shape = new sf::CircleShape(radius);
	this->shape->setFillColor(sf::Color::Green);
	this->x = x;
	this->y = y;
	this->h = radius;
	this->w = radius;
}

GameObject::GameObject(int x, int y, float width, float height) {
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setFillColor(sf::Color::Green);
	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
}

GameObject::~GameObject() {};

void GameObject::move(sf::Vector2f* vect, float deltaT) {
	this->x += vect->x * deltaT;
	this->y += vect->y * deltaT;
	this->shape->setPosition(x, y);
}

void GameObject::rotate(float value) {
	this->shape->rotate(value);
}

bool GameObject::checkCollideRect(GameObject* target) {
	if (this->x < target->x + target->w && this->x + this->w > target->x && this->y < target->y + target->h && this->y + this->h > target->y) {
		return 1;
	}
	return 0;
}



