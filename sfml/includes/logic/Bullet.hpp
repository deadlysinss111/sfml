#pragma once
#include "GameObject.hpp"

#include <SFML/Graphics.hpp>
//class sf::CircleShape;

class Bullet : GameObject {
public:
	Bullet();
	~Bullet();
	sf::CircleShape* shape;
	void move(sf::Vector2f* vect, float deltaT);
};