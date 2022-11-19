#ifndef MOTILE_H
#define MOTILE_H
#include <SFML/Graphics.hpp>
class Motile {
	public:
		virtual void move(sf::Vector2f, sf::Time&) = 0;
		virtual void move(sf::Time&) = 0;
};
#endif
