#pragma once
#include <vector>
#include "../logic/GameObject.hpp"

class Scene {
public:
	Scene() {};
	~Scene() {};

	virtual void render(std::vector<GameObject*>) {};
};