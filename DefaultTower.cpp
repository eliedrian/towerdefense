#include <cmath>
#include "Projectile.h"
#include "TowerProjectile.h"
#include "DefaultTower.h"

DefaultTower::DefaultTower(sf::Vector2f position, sf::Sprite sprite, int damage, float projectileSpeed, float attackSpeed)
	: position(position), sprite(sprite), damage(damage), projectileSpeed(projectileSpeed), attackSpeed(attackSpeed) {
		this->currentAttackTime = 0;
	}

void DefaultTower::placeAt(sf::Vector2f position) {
	this->position = position;
}

void DefaultTower::drawTo(sf::RenderTarget& target) {
	this->sprite.setPosition(this->position);
	target.draw(this->sprite);
}

std::shared_ptr<Projectile> DefaultTower::shoot(Target& target) {
	auto relativePosition = target.position() - this->position;
	auto angle = atan2f(relativePosition.y, relativePosition.x);
	sf::Vector2f velocity(cosf(angle) * this->projectileSpeed, sinf(angle) * this->projectileSpeed);

	if (this->_projectiles.size() == 5) {
		this->_projectiles.pop_front();
	}
	this->_projectiles.push_back(
		std::make_shared<TowerProjectile>(
			this->position,
			this->damage,
			velocity
		)
	);
	return this->_projectiles.back();
}

const std::list<std::shared_ptr<Projectile>> DefaultTower::projectiles() {
	return this->_projectiles;
}

std::shared_ptr<Projectile> DefaultTower::shoot(Target& target, sf::Time& elapsed) {
	this->currentAttackTime += elapsed.asMilliseconds();
	if (this->currentAttackTime < this->attackSpeed) {
		return std::shared_ptr<TowerProjectile>(nullptr);
	}
	this->currentAttackTime -= this->attackSpeed;
	return this->shoot(target);
}
