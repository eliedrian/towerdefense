#include "DefaultAnimatedSprite.h"

DefaultAnimatedSprite::DefaultAnimatedSprite(sf::Sprite sprite, sf::Vector2i initialFrame, sf::Vector2i frameSize, int frameCount, float fps, bool loops) {
	this->sprite = sprite;
	this->sprite.setOrigin(frameSize.x / 2.f, frameSize.y / 2.f);
	this->frameCount = frameCount;
	sf::Vector2i shift(frameSize.x, 0);
	sf::Vector2i position = initialFrame;
	for (int i = 0; i < frameCount; i++) {
		this->frames.push_back(sf::IntRect(position, frameSize));
		position = position + shift;
	}
	this->currentFrameIndex = 0;
	this->currentFrameTime = 0;
	this->fps = fps;
	this->position = sf::Vector2f(0, 0);
	this->loops = loops;
}

void DefaultAnimatedSprite::updateFrame(sf::Time& elapsed) {
	if (this->stopped()) {
		return;
	}
	this->currentFrameTime += elapsed.asMilliseconds();
	float timePerFrame = 1000.f / this->fps;
	int elapsedFrames = this->currentFrameTime / timePerFrame;
	this->currentFrameIndex = this->currentFrameIndex + elapsedFrames;
	if (this->loops) {
		this->currentFrameIndex = this->currentFrameIndex % this->frameCount;
	} else {
		if (this->currentFrameIndex >= this->frameCount) {
			this->currentFrameIndex = this->frameCount - 1;
		}
	}
	this->currentFrameTime -= elapsedFrames * timePerFrame;
}

void DefaultAnimatedSprite::drawTo(sf::RenderTarget& target) {
	this->sprite.setTextureRect(this->frames[this->currentFrameIndex]);
	this->sprite.setPosition(this->position);
	target.draw(this->sprite);
}

void DefaultAnimatedSprite::placeAt(sf::Vector2f position) {
	this->position = position;
}

sf::FloatRect DefaultAnimatedSprite::bounds() {
	return this->sprite.getGlobalBounds();
}

bool DefaultAnimatedSprite::collidesWith(Collidable& collidee) {
	return this->bounds().intersects(collidee.bounds());
}

bool DefaultAnimatedSprite::stopped() {
	if (this->loops) {
		return false;
	}
	return this->currentFrameIndex + 1 == this->frameCount;
}
