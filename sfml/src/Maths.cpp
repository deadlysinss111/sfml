#include <SFML/Graphics.hpp>
#include "../includes/logic/Maths.hpp"
using namespace Maths;

Calcul::Calcul() {}

float Calcul::Onormalizing(float x, float y) {
	float norm = std::sqrt(x * x + y * y);
	return norm;
}

void Calcul::normalized(sf::Vector2f* vect) {
	float norm = Onormalizing(vect->x, vect->y);
	vect->x /= norm;
	vect->y /= norm;
}
