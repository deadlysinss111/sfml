#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(int x, int y, float radius);
	GameObject(int x, int y, float width, float height);
	~GameObject();

	float x;
	float y;
	float h;
	float w;
	void move(float deltaT);
	void rotate(float value);
	bool checkCollideRect(GameObject* target);
	sf::Shape* shape;
	sf::Vector2f* velocity;
	void setVelocity(sf::Vector2f* vect);
	bool collided;

};