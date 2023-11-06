#include "../includes/engine/InputManager.hpp"
//#include "SFML/Graphics.hpp"
//#include <unordered_map>


InputManager::InputManager(sf::RenderWindow* window) {
    this->window = window;
}

InputManager::~InputManager() {};

void InputManager::manage() {
	sf::Event event;
    auto found = this->eventMap.find(&event);
    if (found != this->eventMap.end()) {
        void* test = found->second;
        void(*test)();
        test();
    }
}

void InputManager::bindMap(sf::Event* event, void(*function)()) {
    this->eventMap.insert({ event, function });
}


/*sf::Event::Closed:
            this->window->close();
            break;*/