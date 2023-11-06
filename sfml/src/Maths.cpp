#include <SFML/Graphics.hpp>
#include "../../includes/logic/Maths.hpp"
using namespace Maths;
Calcul::Calcul() {
	float x, y;
	float norm;
}
	float Calcul::Onormalizing(x, y) {
			sqrt(x ^ 2 + y ^ 2) = norm;
	};

	void Calcul::normalized(Vector2f* vect) {
		norm = Onormalizing(x, y);
		sf::Vector2f vector(x / norm, y / norm);
		vect->x /= norm;
		vect->y /= norm;
	};