#ifndef ANIMATABLE_H
#define ANIMATABLE_H
#include <SFML/Graphics.hpp>

class Animatable {
	public:
		virtual void updateFrame(sf::Time&) = 0;
		virtual bool stopped() = 0;
};
#endif
