#pragma once
#include "Scene.hpp"

class BrickBreakerScene : public Scene {
public:
	BrickBreakerScene();
	~BrickBreakerScene();

	void render(std::vector<GameObject*> objectList);
};