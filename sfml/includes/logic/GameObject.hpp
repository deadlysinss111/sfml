#pragma once
#include <SFML/Graphics.hpp>

class InputManager;

class GameObject {
public:
	GameObject();
	~GameObject();

	
	InputManager* inputManager;
	sf::Shape* shape;


	float x;
	float y;
	float h;
	float w;
	sf::Vector2f* velocity;
	
};