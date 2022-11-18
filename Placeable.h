#ifndef PLACEABLE_H
#define PLACEABLE_H
#include <SFML/Graphics.hpp>

class Placeable {
	public:
		virtual void placeAt(sf::Vector2f) = 0;
};
#endif
