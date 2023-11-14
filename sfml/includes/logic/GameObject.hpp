#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace sf
{
	class RenderWindow;
	class Shape;
}

class GameObject {
public:
	GameObject(sf::RenderWindow* window, int x, int y, float width, float height);
	GameObject(sf::RenderWindow* window, int x, int y, float radius);
	GameObject();
	~GameObject();


	sf::RenderWindow* window;
	sf::Shape* shape;
	virtual void f() {};

	virtual bool update(float deltaT, std::vector<GameObject*>* objectVector) { return 0; }
	void display(sf::RenderWindow* window);
	void checkCollideRect(GameObject* target, sf::RenderWindow& window) {};
	virtual void onHit();

	float x;
	float y;
	float h;
	float w;
	bool dead;
	sf::Vector2f velocity;

};
