#pragma once
#include "GameObject.hpp"

//#include <SFML/Graphics.hpp>
//class sf::CircleShape;

class Bullet : GameObject {
public:
	Bullet(InputManager* inputManager, int x, int y, float radius);
	~Bullet();

	//sf::CircleShape* shape;
	void move(float deltaT);
	void checkCollideRect(GameObject* target, sf::RenderWindow& window);
	void setVelocity(sf::Vector2f* vect);
	void adjustPosition(sf::RenderWindow& window);
};
