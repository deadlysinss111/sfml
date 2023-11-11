//#include <SFML/Graphics.hpp>
#define NOMINMAX
#include <Windows.h>
#include "../../includes/logic/Bullet.hpp"

Bullet::Bullet(InputManager* inputManager, int x, int y, float radius) {
	this->inputManager = inputManager;
	this->shape = new sf::CircleShape(radius);
	this->shape->setFillColor(sf::Color::Green);
	this->x = x;
	this->y = y;
	this->h = radius;
	this->w = radius;
	this->velocity = new sf::Vector2f(0.f, 0.f);
};

Bullet::~Bullet() {
    delete this->shape;
};

void Bullet::move(float deltaT) {
    this->x += this->velocity->x * deltaT;
    this->y += this->velocity->y * deltaT;
    this->shape->setPosition(x, y);
}

void Bullet::checkCollideRect(GameObject* target, sf::RenderWindow& window) {
    if (this->x + this->w > 0 && this->x < window.getSize().x && this->y + this->h > 0 && this->y < window.getSize().y) {
        if (this->x < target->x + target->w && this->x + this->w > target->x && this->y < target->y + target->h && this->y + this->h > target->y) {

            float targetXMax = target->x + target->w;
            float targetYMax = target->y + target->h;

            if (target->y < this->y && this->y < targetYMax) {
                this->velocity->y = -this->velocity->y;
                //target->velocity->y = -target->velocity->y;
            }
            else if (target->y < this->y + this->h && this->y + this->h < targetYMax) {
                this->velocity->y = -this->velocity->y;
                //target->velocity->y = -target->velocity->y;

            }
            else if (target->x < this->x && this->x < targetXMax) {
                this->velocity->x = -this->velocity->x;
                //target->velocity->x = -target->velocity->x;

            }
            else if (target->x < this->x + this->w && this->x + this->w < targetXMax) {
                this->velocity->x = -this->velocity->x;
                //target->velocity->x = -target->velocity->x;
            }
        }
    }
}

void Bullet::adjustPosition(sf::RenderWindow& window) {
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

void Bullet::setVelocity(sf::Vector2f* v1) {
    this->velocity = v1;
}

bool Bullet::update(float deltaT, std::vector<GameObject*>* objectVector){
    this->move(deltaT);
    return 1;
}