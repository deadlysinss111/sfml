#include <SFML/Graphics.hpp>
#include "../includes/logic/Maths.hpp"
using namespace Maths;

Calcul::Calcul(){
	this->x = x;
	this->y = y;
}
Calcul::~Calcul() {}

float Calcul::normalizing(float x, float y) {
	float norm = std::sqrt(x * x + y * y);
	return norm;
}

void Calcul::normalized(sf::Vector2f* vect) {
	float norm = normalizing(vect->x, vect->y);
	vect->x /= norm;
	vect->y /= norm;
}

void Calcul::bounceVect(GameObject* targetX, GameObject* targetY){
	this->y += 2 * y;
	this->bounceVect(GameObject* targetX, GameObject * targetY);
	this->bounceVect(this->x - targetX->x, this->y - targetY->y);
}
