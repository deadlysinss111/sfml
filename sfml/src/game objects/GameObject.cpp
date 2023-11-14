#define NOMINMAX

#include "../../includes/logic/GameObject.hpp"

#include <Windows.h>
#include <SFML/Graphics.hpp>

GameObject::GameObject(sf::RenderWindow* window, int x, int y, float width, float height){
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->x = x; this->y = y;
	this->w = width; this->h = height;
	this->velocity.x = 0.f;
	this->velocity.y = 0.f;
	this->shape->setOrigin(sf::Vector2f(w / 2, h / 2));
	this->shape->setPosition(sf::Vector2f(this->x, this->y));
	this->dead = false;
}

    return false; // Indique qu'il n'y a pas eu de collision
}

	GameObject::GameObject(sf::RenderWindow* window, int x, int y, float radius) {
		this->shape = new sf::CircleShape(radius);
		this->shape->setFillColor(sf::Color::Green);
		this->x = x; this->y = y;
		this->h = radius; this->w = radius;
		this->velocity.x = 0.f;
		this->velocity.y = 0.f;
		this->window = window;
	}

	GameObject::GameObject() {};

	GameObject::~GameObject() {
		delete this->shape;
	};

	void GameObject::display(sf::RenderWindow* window) {
		window->draw(*this->shape);
	}

	void GameObject::onHit() {
		//std::cout << "feur";
	}