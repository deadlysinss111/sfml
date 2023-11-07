//#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../includes/logic/GameObject.hpp"
#include "../../includes/logic/Maths.hpp"
Maths::Calcul math;
GameObject::GameObject(int x, int y, float radius) {
	this->shape = new sf::CircleShape(radius);
	this->shape->setFillColor(sf::Color::Green);
	this->x = x;
	this->y = y;
	this->h = radius;
	this->w = radius;
	this->velocity = new sf::Vector2f(100.f, 0.f);
	this->collided = false;
}

GameObject::GameObject(int x, int y, float width, float height) {
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setFillColor(sf::Color::Green);
	this->x = x;
	this->y = y;
	this->w = width;
	this->h = height;
	this->velocity = new sf::Vector2f(100.f, 0.f);
}

GameObject::~GameObject() {};

void GameObject::move(float deltaT) {
	this->x += this->velocity->x * deltaT;
	this->y += this->velocity->y * deltaT;
	this->shape->setPosition(x, y);
}

void GameObject::rotate(float value) {
	this->shape->rotate(value);
}

bool GameObject::checkCollideRect(GameObject* target) {

	/*if (target == this) {
		return 0;
	}*/

	if (this->x < target->x + target->w && this->x + this->w > target->x && this->y < target->y + target->h && this->y + this->h > target->y && !this->collided) {

		float targetXMax = target->x + target->w;
		float targetYMax = target->y + target->h;

		if (target->y < this->y < targetYMax) {
			//math.bounceVectV(this->velocity);
			this->velocity->y = -this->velocity->y;
			std::cout << "test ?"<< std::endl;
			this->collided = true;

		}
		else if (target->y < this->y + this->h < targetYMax) {
			//math.bounceVectV(this->velocity);
			this->velocity->y = -this->velocity->y;
			std::cout << "test2 ?" << std::endl;
			this->collided = true;
		}
		else if (target->x < this->x < targetXMax) {
			//math.bounceVectH(this->velocity);
			this->velocity->x = -this->velocity->x;
			std::cout << "test3 ?" << std::endl;
			this->collided = true;
		}
		else if (target->x < this->x + this->w < targetXMax) {
			//math.bounceVectH(this->velocity);
			this->velocity->x = -this->velocity->x;
			std::cout << "test4 ?" << std::endl;
			this->collided = true;
		}
		
	}
	return 0;
}

void GameObject::setVelocity(sf::Vector2f* vect) {
	this->velocity = vect;
}

