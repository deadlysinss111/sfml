#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject(int x, int y, float radius);
	GameObject(int x, int y, float width, float height);
	~GameObject();

	
	void move(float deltaT);
	void rotate(float value);
	bool checkCollideRect(GameObject* target, sf::RenderWindow& window);
	sf::Shape* shape;
	void setVelocity(sf::Vector2f* vect);
	void adjustPosition(sf::RenderWindow& window);

private:
	float x;
	float y;
	float h;
	float w;
	sf::Vector2f* velocity;
	void cannonRotation(sf::Vector2f* vect);
	sf::Vector2f getOrigine();
};