#include <SFML/Graphics.hpp>
#include "includes/engine/InputManager.hpp"
#include "includes/logic/GameObject.hpp"



int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    // InputManager inputManager(&window); // demander a Peter si c'est une bonne pratique de tout link des le départ plutot que de repasser tout en argument a chaque appels


    GameObject object();

    while (window.isOpen())
    {
        //inputManager.manage()

        window.clear();

        window.display();
    }

    return 0;
}
