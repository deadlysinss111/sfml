#pragma once
#include "GameObject.hpp"
#include "../../includes/engine/InputManager.hpp"
#include "../../includes/logic/Maths.hpp"
namespace Input{
	class InputManager;

		class Cannon : public GameObject {
		public:
			Cannon(InputManager* inputManager, sf::RenderWindow* window);
			~Cannon();

			InputManager* inputManager;

			bool update(float deltaT, std::vector<GameObject*>* objectVector);
			void rotate();
		};
	}
