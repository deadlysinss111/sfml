#include <SFML/Graphics.hpp>
#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include "includes/engine/InputManager.hpp"
#include "includes/logic/GameObject.hpp"
#include "includes/logic/Cannon.hpp"
#include "includes/logic/Bullet.hpp"
#include "includes/logic/GameManager.hpp"


int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "SFML");
    //sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    InputManager inputManager(&window); // demander a Peter si c'est une bonne pratique de tout link des le départ plutot que de repasser tout en argument a chaque appels
    sf::Clock clock;
    GameManager gameManager;

    Cannon object(&inputManager, 100, 50, 100, 50);
    Bullet bullet(&inputManager, 100, 100, 50);
    gameManager.insert(&object);
    gameManager.insert(&bullet);


    //Bullet bullet;
    sf::Vector2f vectOne(50.f, 0.f);
    bullet.setVelocity(&vectOne);

    //std::function<void()> callback = std::bind(GameObject::cannonRotation, &object);

    while (window.isOpen())
    {
        sf::Event event;

        sf::Time elapsed = clock.restart();

        gameManager.manage(elapsed.asSeconds());

        inputManager.manage();

        window.clear();

        window.draw(*bullet.shape);
        window.draw(*object.shape);

        window.display();

        //object.checkCollideRect(&objectTwo, window);
    }

    return 0;
}

