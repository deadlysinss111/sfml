#pragma once
#include <SFML/Graphics.hpp>

class InputManager;

class GameObject {
public:
	GameObject();
	~GameObject();

	
	InputManager* inputManager;
	sf::Shape* shape;
	virtual bool update(float deltaT, std::vector<GameObject*>* objectVector) { return 0; };
	void display(sf::RenderWindow* window);
	void checkCollideRect(GameObject* target, sf::RenderWindow& window) {};

	float x;
	float y;
	float h;
	float w;
	sf::Vector2f* velocity;
	
};