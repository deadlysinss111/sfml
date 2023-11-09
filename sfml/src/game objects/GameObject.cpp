//#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../includes/logic/GameObject.hpp"
#include "../../includes/logic/Maths.hpp"
#include <Windows.h>

using namespace Maths;
GameObject::GameObject(int x, int y, float radius) {
	this->shape = new sf::CircleShape(radius);
	this->shape->setFillColor(sf::Color::Green);
	this->x = x;
	this->y = y;
	this->h = radius;
	this->w = radius;
	this->velocity = new sf::Vector2f(0.f, 0.f);;
}

GameObject::GameObject(int x, int y, float width, float height) {
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setFillColor(sf::Color::Green);
	this->x = GetSystemMetrics(SM_CXSCREEN) / 2 - this->w / 2;
	this->y = GetSystemMetrics(SM_CYSCREEN) - this->y;
	this->w = width;
	this->h = height;
	this->velocity = new sf::Vector2f(0.f, 0.f);
    this->shape->setOrigin(sf::Vector2f(w/2, h/2));
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
    if (this->x + this->w > 0 && this->x < window.getSize().x && this->y + this->h > 0 && this->y < window.getSize().y) {
        if (this->x < target->x + target->w && this->x + this->w > target->x && this->y < target->y + target->h && this->y + this->h > target->y) {

            float targetXMax = target->x + target->w;
            float targetYMax = target->y + target->h;

            if (target->y < this->y && this->y < targetYMax) {
                this->velocity->y = -this->velocity->y;
                target->velocity->y = -target->velocity->y;
            }
            else if (target->y < this->y + this->h && this->y + this->h < targetYMax) {
                this->velocity->y = -this->velocity->y;
                target->velocity->y = -target->velocity->y;

            }
            else if (target->x < this->x && this->x < targetXMax) {
                this->velocity->x = -this->velocity->x;
                target->velocity->x = -target->velocity->x;

            }
            else if (target->x < this->x + this->w && this->x + this->w < targetXMax) {
                this->velocity->x = -this->velocity->x;
                target->velocity->x = -target->velocity->x;
            }

            return true; // Indique qu'il y a eu collision
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



void GameObject::setVelocity(sf::Vector2f* v1) {
	this->velocity = v1;
}

void GameObject::cannonRotation(sf::Vector2f* v1) {
    sf::Mouse::getPosition();
    sf::Vector2f hyp(0, 0);
    hyp.x = v1->x - GetSystemMetrics(SM_CXSCREEN) / 2;
    hyp.y = GetSystemMetrics(SM_CYSCREEN) - v1->y;
    //std::cout << hyp.x << "||" << hyp.y << std::endl;
    sf::Vector2f v2(hyp.x, 0);
    float signe = (hyp.x > 0) ? 1.f : -1.f;

    this->shape->setRotation(signe*180.f*(normalizing(&v2) / normalizing(&hyp)));
    // soit on trouve directement le projeté orthogonal de coordonnées (1, 0) ou (-1, 0), soit on utilise Thalès ? je sais pas vraiment
    // de là on a un triangle rectangle dont on connait deux cotés => trigo pour trouver l'angle et c'est gagné
}

