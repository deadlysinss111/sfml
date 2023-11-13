
//#include <SFML/Graphics.hpp>
/*#include "../../includes/logic/Bullet.hpp"

Bullet::Bullet(sf::RenderWindow* window, int x, int y, float radius) : GameObject(window, x, y, radius) {

};

Bullet::~Bullet() {
    delete this->shape;
};

void Bullet::move(float deltaT) {
    this->x += this->velocity.x * deltaT;
    this->y += this->velocity.y * deltaT;
    this->shape->setPosition(x, y);
}

void Bullet::checkCollideRect(GameObject* target) {
    if (this->x + this->w > 0 && this->x < this->window->getSize().x && this->y + this->h > 0 && this->y < this->window->getSize().y) {
        if (this->x < target->x + target->w && this->x + this->w > target->x && this->y < target->y + target->h && this->y + this->h > target->y) {
            target->onHit();

            float targetXMax = target->x + target->w;
            float targetYMax = target->y + target->h;

            if (target->y < this->y && this->y < targetYMax) {
                this->velocity.y = -this->velocity.y;
                //target->velocity->y = -target->velocity->y;
            }
            else if (target->y < this->y + this->h && this->y + this->h < targetYMax) {
                this->velocity.y = -this->velocity.y;
                //target->velocity->y = -target->velocity->y;

            }
            else if (target->x < this->x && this->x < targetXMax) {
                this->velocity.x = -this->velocity.x;
                //target->velocity->x = -target->velocity->x;

            }
            else if (target->x < this->x + this->w && this->x + this->w < targetXMax) {
                this->velocity.x = -this->velocity.x;
                //target->velocity->x = -target->velocity->x;
            }
        }
    }
}

void Bullet::adjustPosition() {
    if (this->x < 0) {
        this->x = 0;
        this->velocity.x = -this->velocity.x;
    }

    if (this->x + this->w > this->window->getSize().x) {
        this->x = this->window->getSize().x - this->w;
        this->velocity.x = -this->velocity.x;
    }

    if (this->y < 0) {
        this->y = 0;
        this->velocity.y = -this->velocity.y;
    }

    if (this->y + this->h > this->window->getSize().y + 100) {
        this->dead = 1;
    }
}

Bullet::~Bullet() {};

void Bullet::move(sf::Vector2f* vect, float deltaT) {
	this->x += vect->x * deltaT;
	this->y += vect->y * deltaT;
}
*/