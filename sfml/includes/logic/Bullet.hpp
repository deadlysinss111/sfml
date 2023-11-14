#pragma once

#include "GameObject.hpp"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace sf
{
	class RenderWindow;
}


class Bullet : GameObject {
public:
	Bullet(sf::RenderWindow* window, int x, int y, float radius);
	~Bullet();
	sf::CircleShape* shape;
	void move(sf::Vector2f* vect, float deltaT);
};
*/