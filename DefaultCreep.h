#ifndef DEFAULTCREEP_H
#define DEFAULTCREEP_H
#include <bitset>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Creep.h"
#include "Animatable.h"
#include "AnimatedSprite.h"
#include "Collidable.h"
#include "DrawableEntity.h"
#include "HealthBar.h"
#include "Mortal.h"
#include "Motile.h"
#include "Target.h"

#define NORMAL_STATUS   0
#define FLYING_STATUS   1
#define SLOWED_STATUS   2
#define POISONED_STATUS 3
#define ALIVE_STATUS    4
#define DYING_STATUS    5

class DefaultCreep final : public virtual Creep {
	private:
		sf::Vector2f _position;
		std::unique_ptr<AnimatedSprite> sprite;
		std::unique_ptr<AnimatedSprite> deathSprite;
		AnimatedSprite* activeSprite;
		int hp;
		std::bitset<6> status;
		std::unique_ptr<HealthBar> healthBar;
		sf::Vector2f _velocity;

	public:
		DefaultCreep(sf::Vector2f position, std::unique_ptr<AnimatedSprite> sprite, std::unique_ptr<AnimatedSprite> deathSprite, std::unique_ptr<HealthBar> healthBar, sf::Vector2f velocity);
		void move(sf::Vector2f, sf::Time&);
		void drawTo(sf::RenderTarget&);
		void updateFrame(sf::Time&);
		int hitpoints();
		void receiveHit(int);
		void die();
		sf::FloatRect bounds();
		bool collidesWith(Collidable&);
		bool stopped();
		sf::Vector2f position();
		void move(sf::Time&);
};
#endif
