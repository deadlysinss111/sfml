#pragma once
#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject() {};
	~GameObject() {};

	int x;
	int y;
	int h;
	int w;
	int xVelocity;
	int yVelocity;
};