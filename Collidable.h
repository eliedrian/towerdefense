#ifndef COLLIDABLE_H
#define COLLIDABLE_H
#include <SFML/Graphics.hpp>

class Collidable {
	public:
		virtual sf::FloatRect bounds() = 0;
		virtual bool collidesWith(Collidable&) = 0;
};
#endif
