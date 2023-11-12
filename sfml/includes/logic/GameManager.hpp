#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject;
class InputManager;

class GameManager {
public:
	GameManager(InputManager* inputManager, sf::RenderWindow* window);
	~GameManager();

	InputManager* inputManager;
	sf::RenderWindow* window;

	static std::vector<GameObject*>* objectVector;
	bool manage(float deltaT);
	void insert(GameObject* object);
	void shoot();
	void setup();
};