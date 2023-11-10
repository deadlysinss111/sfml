#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "includes/engine/InputManager.hpp"
#include "includes/logic/Brick.hpp"
#include "includes/logic/Canon.hpp"
#include "includes/logic/Bullet.hpp"






int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "SFML");
    //sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    InputManager inputManager(&window); // demander a Peter si c'est une bonne pratique de tout link des le départ plutot que de repasser tout en argument a chaque appels
    sf::Clock clock;

    Canon object(&inputManager, 100, 50, 100, 50);


    //Bullet bullet;
    sf::Vector2f vectOne(1000.f, 500.f);

    //std::function<void()> callback = std::bind(GameObject::cannonRotation, &object);

    while (window.isOpen())
    {
        sf::Event event;
        /*while (window.pollEvent(event)) {
            sf::Vector2f vect(event.mouseMove.x, event.mouseMove.y);
            object.cannonRotation(&vect);
        }*/

        sf::Time elapsed = clock.restart();

        
        inputManager.manage();

        window.clear();

        window.draw(*object.shape);

        window.display();

        object.move(elapsed.asSeconds());

        

        object.adjustPosition(window);
        //object.checkCollideRect(&objectTwo, window);
    }

    return 0;
}

