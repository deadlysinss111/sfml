#include "../includes/logic/GameManager.hpp"
#include "../includes/logic/GameObject.hpp"

// voir pour passer le vecteur en adrese mais ca semble poser quelques soucis
std::vector<GameObject*> GameManager::objectVector = *(new std::vector<GameObject*>);

GameManager::GameManager() {};

GameManager::~GameManager() {};

void GameManager::manage(float deltaT) {
	for (int i = 0; i < this->objectVector.size(); i++) {
		if(this->objectVector[i]->update(deltaT, &objectVector)) {

		};
	}
}

void GameManager::insert(GameObject* object){
	this->objectVector.push_back(object);
}