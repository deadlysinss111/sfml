#include "../../includes/logic/Brick.hpp"

Brick::Brick() {


	this->rect = new sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
	this->rect->setFillColor(sf::Color::Red);
	this->rect->x = 400;
	this->rect->y = 500;
	this->rect->h = 80;
	this->rect->w = 160;
};


Brick::~Brick() {};