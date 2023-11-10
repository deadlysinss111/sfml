#include "../includes/engine/InputManager.hpp"



InputManager::InputManager(sf::RenderWindow* window) {
    this->window = window;
}

InputManager::~InputManager() {};

void InputManager::manage() {
    sf::Event event;

    while (this->window->pollEvent(event))
    {
         switch (event.type) {
         case sf::Event::KeyPressed:
         {
             auto found = this->keyMap.find(event.key.code);
             if (found != keyMap.end())
             {
                 std::cout << "oihbopsh" << std::endl;
                 found->second();
             }
             break;
         }
         case sf::Event::MouseButtonPressed:
         {
             auto found = this->keyMap.find(event.key.code);
             if (found != keyMap.end())
             {
                 found->second();
             }
             break;
         }
         case sf::Event::MouseMoved:
         {
             for (int i = 0; i < this->moveEffect.size(); i++) {
                 this->moveEffect[i]();
             }
         }
         }
    }
}


void InputManager::keyMapping(sf::Keyboard::Key key, void(*function)()) {
    this->keyMap.insert({ key, function });
}

void InputManager::mouseMapping(sf::Mouse::Button button, void(*function)()) {
    this->mouseMap.insert({ button, function });
}

void InputManager::moveMapping(std::function<void()> function) {
    this->moveEffect.push_back(function);
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