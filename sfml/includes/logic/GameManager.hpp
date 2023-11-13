#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

class GameObject;
class InputManager;

class GameManager {
public:
	GameManager(InputManager* inputManager, sf::RenderWindow* window);
	~GameManager();

	InputManager* inputManager;
	sf::RenderWindow* window;
	static std::vector<GameObject*> objectVector;
	static std::map<std::string, sf::Font> fontMap;
	int maxBullets;
	int currentBullets;
	sf::Text scoreText;
	int scoreLogic;

	bool manage(float deltaT);
	void insert(GameObject* object);
	void shoot();
	void setup();
	void addFont(std::string name, const char* path);
	void scoreSetup();
	void scoreUpdate(int value);
};