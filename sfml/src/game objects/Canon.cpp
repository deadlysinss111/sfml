#include "../../includes/logic/Canon.hpp"

Canon::Canon() : GameObject() {
	sf::RectangleShape oRectangle(sf::Vector2f(50.f, 50.f));
	//A la position 100, 100
	oCircle.setPosition(100.f, 100.f);
	//Et de couleur rouge
	oRectangle.setFillColor(sf::Color::Red);

	this->rect = new RectangleShape;
	this->rect->x = 200;
	this->rect->y = 50;
	this->rect->h = 80;
	this->rect->w = 80;



	void Canon::rotation{

	}

};

Canon::~Canon() {};