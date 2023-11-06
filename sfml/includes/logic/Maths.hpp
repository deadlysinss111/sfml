#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
namespace Maths {
    class Calcul : GameObject {
    public:
        float x;
        float y;
        float point;
        Calcul();
        ~Calcul();
        float normalizing(float x, float y);
        void normalized(sf::Vector2f* vect);
        void bounceVect(GameObject* targetX, GameObject* targetY);
    };
}
