#include "../../includes/logic/GameObject.hpp"

GameObject::GameObject() {}

GameObject::~GameObject() {};

void GameObject::display(sf::RenderWindow* window) {
	window->draw(*this->shape);
}