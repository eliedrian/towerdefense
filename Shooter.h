#ifndef SHOOTER_H
#define SHOOTER_H
#include <memory>
#include <list>

#include <SFML/Graphics.hpp>

#include "Projectile.h"
#include "Target.h"

class Shooter {
	public:
		virtual std::shared_ptr<Projectile> shoot(Target&) = 0;
		virtual std::shared_ptr<Projectile> shoot(Target&, sf::Time& elapsed) = 0;
		virtual const std::list<std::shared_ptr<Projectile>> projectiles() = 0;
};
#endif
