#define NOMINMAX
#include <Windows.h>
#include <functional>
#include "../../includes/logic/Cannon.hpp"
#include "../../includes/logic/Maths.hpp"
#include "../../includes/engine/InputManager.hpp"

Cannon::Cannon(InputManager* inputManager, int x, int y, float width, float height) {
	this->inputManager = inputManager;
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setFillColor(sf::Color::Green);
	this->x = GetSystemMetrics(SM_CXSCREEN) / 2 - this->w / 2;
	this->y = GetSystemMetrics(SM_CYSCREEN) - this->y;
	this->w = width;
	this->h = height;
	this->velocity = new sf::Vector2f(0.f, 0.f);
	this->shape->setOrigin(sf::Vector2f(w / 2, h / 2));
	this->shape->setPosition(sf::Vector2f(this->x, this->y));
	this->inputManager->moveMapping(std::bind(&Cannon::rotate, this));
};

Cannon::~Cannon() {};

void Cannon::rotate(){
	sf::Vector2i v1 = sf::Mouse::getPosition();
	sf::Vector2f hyp(0, 0);
	hyp.x = v1.x - GetSystemMetrics(SM_CXSCREEN) / 2;
	hyp.y = GetSystemMetrics(SM_CYSCREEN) - v1.y;
	sf::Vector2f v2(hyp.x, 0);
	float signe = (hyp.x > 0) ? 1.f : -1.f;

	this->shape->setRotation(signe * 180.f * (Maths::normalizing(&v2) / Maths::normalizing(&hyp)));
	// on doit établir le projeté orthogonal de vect sur la droite qui passe par l'origine dirigée par le vecteur (1, 0)
	// de là on a un triangle rectangle dont on connait deux cotés => trigo pour trouver l'angle et c'est gagné
}