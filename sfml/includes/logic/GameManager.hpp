#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GameObject;

class GameManager {
public:
	GameManager();
	~GameManager();

	static std::vector<GameObject*> objectVector;
	void manage(float deltaT);
	void insert(GameObject* object);
};