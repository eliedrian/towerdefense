#include "DefaultCreep.h"

DefaultCreep::DefaultCreep(sf::Vector2f position, std::unique_ptr<AnimatedSprite> sprite, std::unique_ptr<AnimatedSprite> deathSprite, std::unique_ptr<HealthBar> healthBar, sf::Vector2f velocity)
	: sprite(std::move(sprite)), deathSprite(std::move(deathSprite)), healthBar(std::move(healthBar)) {
	this->_position = position;
	this->activeSprite = this->sprite.get();
	this->status.set(NORMAL_STATUS);
	this->status.set(ALIVE_STATUS);
	this->hp = 30;
	this->_velocity = velocity;
}

void DefaultCreep::move(sf::Vector2f velocity, sf::Time& elapsed) {
	if (!this->status[ALIVE_STATUS]) {
		return;
	}
	sf::Vector2f scaled(velocity.x * elapsed.asSeconds(), velocity.y * elapsed.asSeconds());
	this->_position += scaled;
}

void DefaultCreep::drawTo(sf::RenderTarget& target) {
	if (!this->status.any()) {
		return;
	}
	this->healthBar->placeAt(this->_position);
	this->activeSprite->placeAt(this->_position);
	this->healthBar->drawTo(target);
	this->activeSprite->drawTo(target);
}

void DefaultCreep::updateFrame(sf::Time& elapsed) {
	if (!this->status.any()) {
		return;
	}
	if (this->status[DYING_STATUS] && this->stopped()) {
		this->status.reset();
	}
	this->activeSprite->updateFrame(elapsed);
}

int DefaultCreep::hitpoints() {
	return this->hp;
}

void DefaultCreep::receiveHit(int damage) {
	this->hp -= damage;
	this->healthBar->fillTo(this->hp / 30.f);
	if (this->hp <= 0) {
		this->die();
	}
}

void DefaultCreep::die() {
	this->status.reset();
	this->status.set(DYING_STATUS);
	this->activeSprite = this->deathSprite.get();
}

sf::FloatRect DefaultCreep::bounds() {
	if (!this->status.test(ALIVE_STATUS)) {
		return sf::FloatRect(this->_position, sf::Vector2f(0, 0));
	}
	auto spriteBounds = this->activeSprite->bounds();
	return sf::FloatRect(this->_position, sf::Vector2f(spriteBounds.width, spriteBounds.height));
}

bool DefaultCreep::collidesWith(Collidable& collidee) {
	return this->bounds().intersects(collidee.bounds());
}

bool DefaultCreep::stopped() {
	return this->activeSprite->stopped();
}

sf::Vector2f DefaultCreep::position() {
	return this->_position;
}

void DefaultCreep::move(sf::Time& elapsed) {
	this->move(this->_velocity, elapsed);
}
