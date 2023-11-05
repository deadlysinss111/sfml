#include <SFML/Graphics.hpp>

class GameObject {
public:
	GameObject() {};
	~GameObject() {};

	int x;
	int y;
	int xVelocity;
	int yVelocity;
};