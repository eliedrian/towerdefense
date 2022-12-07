#ifndef TARGET_H
#define TARGET_H
#include <SFML/Graphics.hpp>

class Target {
	public:
		virtual sf::Vector2f position() = 0;
};
#endif
