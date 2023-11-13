#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../engine/InputManager.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Brick.hpp"
#include "Cannon.hpp"
#include "../engine/InputManager.hpp"
#include "Maths.hpp"
namespace Input {

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
}

