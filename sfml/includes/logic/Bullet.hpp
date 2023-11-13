#pragma once
#include "GameObject.hpp"


class Bullet : public GameObject {
public:
	Bullet(sf::RenderWindow* window, int x, int y);
	~Bullet();
	bool update(float deltaT, std::vector<GameObject*>* objectVector);

	//sf::CircleShape* shape;
	//void display(sf::RenderWindow*);
	void move(float deltaT);
	void checkCollideRect(GameObject* target);
	void setVelocity(sf::Vector2f* vect);
	void adjustPosition();
	void onHit(GameObject* target);

};
