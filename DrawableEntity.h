#ifndef DRAWABLEENTITY_H
#define DRAWABLEENTITY_H
#include <SFML/Graphics.hpp>

class DrawableEntity {
	public:
		virtual void drawTo(sf::RenderTarget&) = 0; 
};
#endif
