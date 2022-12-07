#ifndef DEFAULTTOWER_H
#define DEFAULTTOWER_H
#include <memory>
#include <list>

#include <SFML/Graphics.hpp>
#include "Tower.h"

class DefaultTower final : public virtual Tower {
	private:
		sf::Vector2f position;
		sf::Sprite sprite;
		int damage;
		float projectileSpeed;
		float attackSpeed;
		float currentAttackTime;
		std::list<std::shared_ptr<Projectile>> _projectiles;

	public:
		DefaultTower(sf::Vector2f position, sf::Sprite sprite, int damage, float projectileSpeed, float attackSpeed);
		void placeAt(sf::Vector2f position);
		void drawTo(sf::RenderTarget& target);
		std::shared_ptr<Projectile> shoot(Target& target);
		std::shared_ptr<Projectile> shoot(Target& target, sf::Time& elapsed);
		const std::list<std::shared_ptr<Projectile>> projectiles();
};
#endif
