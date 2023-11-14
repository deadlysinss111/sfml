#pragma once

#include <vector>
#include <map>
#include <string>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class InputManager;
class GameObject;

namespace sf 
{
    class RenderWindow;
}


class GameManager {
public:

		InputManager* inputManager;
		sf::RenderWindow* window;

    bool manage(float deltaT);
    void insert(GameObject* object);
    //void shoot();
    void setup();
    void addFont(std::string name, const char* path);
    void scoreSetup();
    void scoreUpdate(int value);

