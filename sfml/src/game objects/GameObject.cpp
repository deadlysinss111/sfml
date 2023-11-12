#include "../../includes/logic/GameObject.hpp"
#include <iostream>

GameObject::GameObject() {
	this->dead = false;
}

GameObject::~GameObject() {};

void GameObject::display(sf::RenderWindow* window) {
	window->draw(*this->shape);
}

void GameObject::onHit() {
	//std::cout << "feur";
}