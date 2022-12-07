#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Grid.h"

Grid::Grid(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
}

void Grid::drawTo(sf::RenderTarget& target) {
	auto windowSize = target.getView().getSize();
	auto vSize = windowSize.y / this->rows;
	auto hSize = windowSize.x / this->cols;
	std::vector<sf::Vertex> vertices;

	for (int i = 0, j = 0; i < (this->rows + 1) * 2; i++, j++) {
		vertices.push_back(
			sf::Vertex(
				sf::Vector2f(windowSize.x * (i % 2), vSize * (j / 2)),
				sf::Color::White
			)
		);
	}
	for (int i = 0, j = 0; i < (this->cols + 1) * 2; i++, j++) {
		vertices.push_back(
			sf::Vertex(
				sf::Vector2f(hSize * (i / 2), windowSize.y * (j % 2)),
				sf::Color::White
			)
		);
	}
	for (int i = 0; i < vertices.size() / 2; i++) {
		target.draw(&vertices[i * 2], 2, sf::Lines);
	}
}
