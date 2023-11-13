#include <iostream>
#include "../includes/logic/GameManager.hpp"
namespace Input {
	// voir pour passer le vecteur en adrese mais ca semble poser quelques soucis
	std::vector<GameObject*>* GameManager::objectVector = new std::vector<GameObject*>;

	GameManager::GameManager(InputManager* inputManager, sf::RenderWindow* window) {
		this->inputManager = inputManager;
		this->window = window;
		this->inputManager->mouseMapping(sf::Mouse::Left, std::bind(&GameManager::shoot, this));
		this->setup();
	};

	GameManager::~GameManager() {};

	bool GameManager::manage(float deltaT) {
		for (int i = 0; i < this->objectVector->size(); i++) {
			this->objectVector->at(i)->update(deltaT, objectVector);
			this->objectVector->at(i)->display(this->window);
			if (this->objectVector->at(i)->dead) {
				objectVector->erase(objectVector->begin() + i);
				if (this->objectVector->size() <= 1) {
					return false;
				}
			}
		}
		return true;
	}

	void GameManager::insert(GameObject* object) {
		this->objectVector->push_back(object);
	}

	void GameManager::shoot() {
		Bullet* bullet = new Bullet(this->window, this->window->getSize().x / 2, this->window->getSize().y, 25);
		//Bullet* bullet = new Bullet(this->inputManager, this->window, 200, 200, 50);
		sf::Vector2f mouseVect(sf::Vector2f(sf::Mouse::getPosition().x - bullet->x, sf::Mouse::getPosition().y - bullet->y));
		Maths::normalized(&mouseVect);
		mouseVect.x *= 500;
		mouseVect.y *= 500;
		bullet->setVelocity(&mouseVect);
		this->objectVector->push_back(bullet);
		//std::cout << mouseVect.x << "||" << mouseVect.y << std::endl;
	}

	void GameManager::setup() {
		Cannon* cannon = new Cannon(this->inputManager, this->window);
		this->objectVector->push_back(cannon);
		for (int i = 0; i < 10; i++) {
			Brick* brick = new Brick(this->inputManager, this->window, i, 0, 2);
			this->objectVector->push_back(brick);
		}
	}
}