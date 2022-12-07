#ifndef GRID_H
#define GRID_H
#include <SFML/Graphics.hpp>
#include "DrawableEntity.h"

class Grid final : public DrawableEntity {
	private:
		int rows;
		int cols;
	public:
		Grid(int rows, int cols);
		void drawTo(sf::RenderTarget&);
};
#endif
