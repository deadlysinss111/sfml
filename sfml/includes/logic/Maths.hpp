#pragma once
#include <SFML/Graphics.hpp>
namespace Maths {
    class Calcul{
    public:
        float x;
        float y;
        Calcul();
        ~Calcul();
        float normalizing(sf::Vector2f* vect);
        void normalized(sf::Vector2f* vect);
        void bounceVectH(sf::Vector2f* vect);
        void bounceVectV(sf::Vector2f* vect);
    };
}
