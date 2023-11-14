#define NOMINMAX

#include "../../includes/logic/Brick.hpp"

#include  <windows.h>
#include  <SFML/Graphics.hpp>

std::map<int, sf::Color> Brick::colorMap{
	{1, sf::Color::Red},
	{2, sf::Color::Blue},
	{3, sf::Color::Green}
};

Brick::Brick(sf::RenderWindow* window, int x, int y, int hp) : GameObject(window, 100 +121 * x , 20 + 32 * y, 120, 30) {
	this->hp = hp;
}


	this->rect = new sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
	this->rect->setFillColor(sf::Color::Red);
	this->rect->x = 400;
	this->rect->y = 500;
	this->rect->h = 80;
	this->rect->w = 160;
};


Brick::~Brick() {}; */