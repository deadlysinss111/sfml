#include "../includes/engine/InputManager.hpp"
//#include <>
//#include "SFML/Graphics.hpp"


InputManager::InputManager(sf::RenderWindow* window) {
    this->window = window;
};

InputManager::~InputManager() {};

void InputManager::manage() {
	sf::Event event;

    while (this->window->pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::MouseMoved:
            break;
        
        }
    }
}