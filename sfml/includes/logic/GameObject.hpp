#pragma once

class InputManager;
namespace sf {
	class Shape;
	class CircleShape;
	class RectangleShape;
	class RenderWindow;
	class Vector2f;
};

class GameObject {
public:
	GameObject(InputManager* inputManager, int x, int y, float radius);
	GameObject(InputManager* inputManager, int x, int y, float width, float height);
	~GameObject();

	InputManager* inputManager;
	sf::Shape* shape;


	float x;
	float y;
	float h;
	float w;
	sf::Vector2f* velocity;
	
};