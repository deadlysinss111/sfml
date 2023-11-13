#pragma once
#include <SFML/Graphics.hpp>

class InputManager;

class GameObject {
public:
	GameObject(InputManager* inputManager, sf::RenderWindow* window, int x, int y, float width, float height);
	GameObject(InputManager* inputManager, sf::RenderWindow* window, int x, int y, float radius);
	GameObject();
	~GameObject();

	
	InputManager* inputManager;
	sf::RenderWindow* window;
	sf::Shape* shape;
	virtual bool update(float deltaT, std::vector<GameObject*>* objectVector) { return 0; };
	void display(sf::RenderWindow* window);
	void checkCollideRect(GameObject* target, sf::RenderWindow& window) {};
	virtual void onHit(GameObject* target);

	float x;
	float y;
	float h;
	float w;
	bool dead;
	
	sf::Vector2f velocity;
	
};