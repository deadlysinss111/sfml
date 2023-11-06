#include <SFML/Graphics.hpp>
#include "includes/engine/InputManager.hpp"
#include "includes/logic/Bullet.hpp"



int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");
    InputManager inputManager(&window); // demander a Peter si c'est une bonne pratique de tout link des le départ plutot que de repasser tout en argument a chaque appels
    sf::Clock clock;


    Bullet bullet;
    sf::Vector2f vect(1.f, 1.f);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        inputManager.manage();

        window.clear();

        window.draw((sf::Drawable&)bullet.shape);

        window.display();

        bullet.move(&vect, elapsed.asSeconds());
    }

    return 0;
}
