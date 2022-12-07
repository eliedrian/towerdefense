#ifndef HEALTHBAR_H
#define HEALTHBAR_H
#include <SFML/Graphics.hpp>

#include "DrawableEntity.h"
#include "Fillable.h"
#include "Placeable.h"

class HealthBar : public DrawableEntity, public Placeable, public Fillable {
	private:
		sf::Vector2f position;
		float percentFill;
	public:
		HealthBar(sf::Vector2f, float);
		void drawTo(sf::RenderTarget&);
		void placeAt(sf::Vector2f);
		void fillTo(float);
};
#endif
