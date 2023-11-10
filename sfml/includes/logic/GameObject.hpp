#pragma once
#include <SFML/Graphics.hpp>

class InputManager;

class GameObject {
public:
	GameObject(InputManager* inputManager, int x, int y, float radius);
	GameObject(InputManager* inputManager, int x, int y, float width, float height);
	~GameObject();

	
	InputManager* inputManager;
	void move(float deltaT);
	void rotate(float value);
	bool checkCollideRect(GameObject* target, sf::RenderWindow& window);
	sf::Shape* shape;
	void setVelocity(sf::Vector2f* vect);
	void adjustPosition(sf::RenderWindow& window);
	//void cannonRotation(sf::Vector2f* vect);
	void cannonRotation();

private:
	float x;
	float y;
	float h;
	float w;
	sf::Vector2f* velocity;
	
};