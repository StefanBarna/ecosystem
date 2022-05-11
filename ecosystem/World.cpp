#include "World.h"

World::World(int size) : m_size(size) {
	// create the 2D grid
	this->m_grid = new Tile * *[this->m_size];
	for (int i = 0; i < this->m_size; ++i) {
		this->m_grid[i] = new Tile * [this->m_size];
	}

	// initialize the 2D grid
	for (int i = 0; i < this->m_size; ++i) {
		for (int j = 0; j < this->m_size; ++j) {
			this->m_grid[i][j] = nullptr;
		}
	}
}