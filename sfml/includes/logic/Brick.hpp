#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics.hpp>

#include <SFML/Graphics/Color.hpp>
#include <map>

namespace sf
{
	class RenderWindow;
}


class Brick : public GameObject {
public:
	Brick(sf::RenderWindow* window, int x, int y, int hp);
	~Brick();
	sf::RectangleShape* rectangle;
};
*/