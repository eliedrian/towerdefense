#include <SFML/Graphics.hpp>

#include "HealthBar.h"

HealthBar::HealthBar(sf::Vector2f position, float percentFill) {
	this->position = position;
	this->percentFill = percentFill;
}

void HealthBar::drawTo(sf::RenderTarget& target) {
	sf::RectangleShape bar(sf::Vector2f(30.f, 2.f));
	bar.setFillColor(sf::Color::Red);
	bar.setOrigin(15.f, 20);
	bar.setPosition(this->position);
	bar.setOutlineColor(sf::Color::White);
	bar.setOutlineThickness(1);

	sf::RectangleShape fill(sf::Vector2f(30.f * this->percentFill, 2.f));
	fill.setFillColor(sf::Color::Green);
	fill.setOrigin(15.f, 20);
	fill.setPosition(this->position);
	target.draw(bar);
	target.draw(fill);
}

void HealthBar::placeAt(sf::Vector2f position) {
	this->position = position;
}

void HealthBar::fillTo(float percentFill) {
	this->percentFill = percentFill;
}
