#include "../includes/engine/InputManager.hpp"
//#include "SFML/Graphics.hpp"
//#include <unordered_map>
#include <iostream>


void test() {
    std::cout << "ughgughgughg";
}

InputManager::InputManager(sf::RenderWindow* window) {
    this->window = window;
    this->eventMap = {{sf::Keyboard::Escape, test}};
}

InputManager::~InputManager() {};

void InputManager::manage() {
    sf::Event event;

    while (this->window->pollEvent(event))
    {
         switch (event.type) {
         case sf::Event::KeyPressed:
             auto found = this->eventMap.find(event.key.code);
             if (found != eventMap.end())
             {
                 found->second();
             }
         }
    }
}


	/*sf::Event event;
    auto found = this->eventMap.find(&event);
    if (found != this->eventMap.end()) {
        void* test = found->second;
        void(*test)();
        test();
    }*/


/*sf::Event::Closed:
            this->window->close();
            break;*/