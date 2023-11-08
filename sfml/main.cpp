#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include "includes/engine/InputManager.hpp"
#include "includes/logic/GameObject.hpp"


void testFunc(){
    std::cout << "great job babe";
}


int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN)), "SFML");
    //sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    //InputManager inputManager(&window); // demander a Peter si c'est une bonne pratique de tout link des le départ plutot que de repasser tout en argument a chaque appels
    sf::Clock clock;

    GameObject object(100, 100, 200);
    GameObject objectTwo(600, 100, 200);


    //inputManager.bindMap(esc, testFunc);


    //Bullet bullet;
    sf::Vector2f vectOne(100.f, 0.f);
    object.setVelocity(&vectOne);
    sf::Vector2f vectTwo(-100.f, 0.f);
    objectTwo.setVelocity(&vectTwo);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        //inputManager.manage();

        window.clear();

        window.draw(*object.shape);
        window.draw(*objectTwo.shape);

        window.display();

        object.move(elapsed.asSeconds());
        objectTwo.move(elapsed.asSeconds());
        object.adjustPosition(window);
        objectTwo.adjustPosition(window);


        object.checkCollideRect(&objectTwo, window);
    }

    return 0;
}


= new Vector2f(0, 0)