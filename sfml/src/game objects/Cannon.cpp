#define NOMINMAX
#include <Windows.h>
#include <functional>
#include "../../includes/logic/Cannon.hpp"
namespace Input {

	class InputManager;

	Cannon::Cannon(InputManager* inputManager, sf::RenderWindow* window) : GameObject(window, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN), 100, 50){
		this->inputManager->moveMapping(std::bind(&Cannon::rotate, this));
	};

	Cannon::~Cannon() {
	
	};

	void Cannon::rotate(){
		sf::Vector2i v1 = sf::Mouse::getPosition();
		sf::Vector2f hyp(0, 0);
		hyp.x = v1.x - GetSystemMetrics(SM_CXSCREEN) / 2;
		hyp.y = GetSystemMetrics(SM_CYSCREEN) - v1.y;
		sf::Vector2f v2(hyp.x, 0);
		float signe = (hyp.x > 0) ? 1.f : -1.f;

		this->shape->setRotation(signe * 180.f * (Maths::normalizing(&v2) / Maths::normalizing(&hyp)));
		// on doit �tablir le projet� orthogonal de vect sur la droite qui passe par l'origine dirig�e par le vecteur (1, 0)
		// de l� on a un triangle rectangle dont on connait deux cot�s => trigo pour trouver l'angle et c'est gagn�
	}

	bool Cannon::update(float deltaT, std::vector<GameObject*>* objectVector) {
		return 0;
	}
}