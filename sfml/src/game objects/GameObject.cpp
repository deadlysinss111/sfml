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

GameObject::~GameObject() {
	delete this->velocity;
};

void GameObject::move(float deltaT) {
	this->x += this->velocity->x * deltaT;
	this->y += this->velocity->y * deltaT;
	this->shape->setPosition(x, y);
}

void GameObject::rotate(float value) {
	this->shape->rotate(value);
}

bool GameObject::checkCollideRect(GameObject* target, sf::RenderWindow& window) {
    if (!this->collided) {
        if (this->x + this->w > 0 && this->x < window.getSize().x && this->y + this->h > 0 && this->y < window.getSize().y) {
            if (this->x < target->x + target->w && this->x + this->w > target->x && this->y < target->y + target->h && this->y + this->h > target->y) {

                float targetXMax = target->x + target->w;
                float targetYMax = target->y + target->h;

                if (target->y < this->y && this->y < targetYMax) {
                    this->velocity->y = -this->velocity->y;
                    target->velocity->y = -target->velocity->y;
                    this->collided = true;
                }
                else if (target->y < this->y + this->h && this->y + this->h < targetYMax) {
                    this->velocity->y = -this->velocity->y;
                    target->velocity->y = -target->velocity->y;
                    this->collided = true;
                }
                else if (target->x < this->x && this->x < targetXMax) {
                    this->velocity->x = -this->velocity->x;
                    target->velocity->x = -target->velocity->x;
                    this->collided = true;
                }
                else if (target->x < this->x + this->w && this->x + this->w < targetXMax) {
                    this->velocity->x = -this->velocity->x;
                    target->velocity->x = -target->velocity->x;
                    this->collided = true;
                }

                return true; // Indique qu'il y a eu collision
            }
        }
    }

    return false; // Indique qu'il n'y a pas eu de collision
}

void GameObject::adjustPosition(sf::RenderWindow& window) {
    if (this->x < 0) {
        this->x = 0;
        this->velocity->x = -this->velocity->x;
    }

    if (this->x + this->w > window.getSize().x) {
        this->x = window.getSize().x - this->w;
        this->velocity->x = -this->velocity->x;
    }

    if (this->y < 0) {
        this->y = 0;
        this->velocity->y = -this->velocity->y;
    }

    if (this->y + this->h > window.getSize().y) {
        this->y = window.getSize().y - this->h;
        this->velocity->y = -this->velocity->y;
    }
}



void GameObject::setVelocity(sf::Vector2f* vect) {
	this->velocity = vect;
}

