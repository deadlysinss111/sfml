#pragma once
#include <SFML/Graphics.hpp>
namespace Maths {
    class Calcul {
        float x; 
        float y;
    public:
        Calcul();
        float Onormalizing(float x, float y);
        void normalized(sf::Vector2f* vect);
    };
}
