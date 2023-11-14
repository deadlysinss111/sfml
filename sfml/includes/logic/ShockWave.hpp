#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "../../includes/engine/InputManager.hpp"
#include "../../includes/logic/Maths.hpp"

class ShockWave : public GameObject {
public:
	ShockWave(sf::RenderWindow* window, sf::Vector2f* direction);
	~ShockWave();

	sf::Vector2f v1;
	sf::Vector2f v2;

	bool update(float deltaT, std::vector<GameObject*>* objectVector);
	void calculateBase(sf::Vector2f*);
	void rotateShape();
};
