#include "TowerProjectile.h"

TowerProjectile::TowerProjectile(sf::Vector2f origin, int damage, sf::Vector2f velocity) {
	this->currentPosition = origin;
	this->dmg = damage;
	this->active = true;
	this->velocity = velocity;
}

void TowerProjectile::drawTo(sf::RenderTarget& target) {
	if (!this->active) {
		return;
	}
	sf::CircleShape p(2.f);
	p.setPosition(this->currentPosition);
	p.setFillColor(sf::Color::Cyan);
	target.draw(p);
}

void TowerProjectile::move(sf::Vector2f velocity, sf::Time& elapsed) {
	if (!this->active) {
		return;
	}
	sf::Vector2f scaled(velocity.x * elapsed.asSeconds(), velocity.y * elapsed.asSeconds());
	this->currentPosition += scaled;
}

bool TowerProjectile::collidesWith(Collidable& collidee) {
	return this->bounds().intersects(collidee.bounds());
}

sf::FloatRect TowerProjectile::bounds() {
	if (!this->active) {
		return sf::FloatRect(this->currentPosition, sf::Vector2f(0, 0));
	}
	return sf::FloatRect(this->currentPosition, sf::Vector2f(3.f, 3.f));
}

void TowerProjectile::damage(Mortal& mortal) {
	mortal.receiveHit(this->dmg);
}

int TowerProjectile::hitpoints() {
	return this->active;
}

void TowerProjectile::receiveHit(int damage) {
	return;
}

void TowerProjectile::die() {
	this->active = false;
}

void TowerProjectile::move(sf::Time& elapsed) {
	this->move(this->velocity, elapsed);
}
