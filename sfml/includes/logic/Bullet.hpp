#pragma once
#include "GameObject.hpp"

//#include <SFML/Graphics.hpp>
//class sf::CircleShape;

class Bullet : public GameObject {
public:
	Bullet(InputManager* inputManager, sf::RenderWindow* window, int x, int y, float radius);
	~Bullet();
	bool update(float deltaT, std::vector<GameObject*>* objectVector);

	//sf::CircleShape* shape;
	//void display(sf::RenderWindow*);
	void move(float deltaT);
	void checkCollideRect(GameObject* target);
	void setVelocity(sf::Vector2f* vect);
	void adjustPosition();
};
