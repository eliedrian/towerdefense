#ifndef DEFAULTANIMATEDSPRITE_H
#define DEFAULTANIMATEDSPRITE_H
#include <vector>
#include <SFML/Graphics.hpp>

#include "Animatable.h"
#include "DrawableEntity.h"
#include "Placeable.h"
#include "Collidable.h"
#include "AnimatedSprite.h"

class DefaultAnimatedSprite final : public virtual AnimatedSprite {
	private:
		sf::Sprite sprite;
		int frameCount;
		std::vector<sf::IntRect> frames;
		int currentFrameIndex;
		float currentFrameTime;
		float fps;
		sf::Vector2f position;
		bool loops;
	public:
		DefaultAnimatedSprite(sf::Sprite sprite, sf::Vector2i initialFrame, sf::Vector2i frameSize, int frameCount, float fps, bool loops);
		void updateFrame(sf::Time&);
		void drawTo(sf::RenderTarget&);
		void placeAt(sf::Vector2f);
		sf::FloatRect bounds();
		bool collidesWith(Collidable&);
		bool stopped();
};
#endif
