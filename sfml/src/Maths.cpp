#include <SFML/Graphics.hpp>
#include "../includes/logic/Maths.hpp"
#include<iostream>
using namespace Maths;

Calcul::Calcul(){
	this->x = x;
	this->y = y;
}
Calcul::~Calcul() {}

float Calcul::normalizing(sf::Vector2f* vect) {
	float norm = std::sqrt(vect->x * vect->x + vect->y * vect->y);
	return norm;
}

void Calcul::normalized(sf::Vector2f* vect) {
	float norm = normalizing(vect);
	vect->x /= norm;
	vect->y /= norm;
}

void Calcul::bounceVectH(sf::Vector2f* vect){
	vect->x = -vect->x;
	std::cout<< "yo";
}
void Calcul::bounceVectV(sf::Vector2f* vect) {
	vect->y = -vect->y;
}
