#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(int x, int y, float radius);
	GameObject(int x, int y, float width, float height);
	~GameObject();

	void move(sf::Vector2f* vect, float deltaT);
	void rotate(float value);
	bool checkCollideRect(GameObject* target);
	sf::Shape* shape;

private:
	float x;
	float y;
	float h;
	float w;
	sf::Vector2f* velocity;

};