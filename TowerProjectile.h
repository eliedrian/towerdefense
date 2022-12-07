#ifndef TOWERPROJECTILE_H
#define TOWERPROJECTILE_H
#include <SFML/Graphics.hpp>

#include "Collidable.h"
#include "Damager.h"
#include "DrawableEntity.h"
#include "Mortal.h"
#include "Motile.h"
#include "Projectile.h"

class TowerProjectile final : public virtual Projectile {
	private:
		sf::Vector2f currentPosition;
		int dmg;
		bool active;
		sf::Vector2f velocity;
	public:
		TowerProjectile(sf::Vector2f origin, int damage, sf::Vector2f velocity);
		void drawTo(sf::RenderTarget&);
		void move(sf::Vector2f, sf::Time&);
		bool collidesWith(Collidable&);
		sf::FloatRect bounds();
		void damage(Mortal&);
		int hitpoints();
		void receiveHit(int);
		void die();
		void move(sf::Time&);
};
#endif
