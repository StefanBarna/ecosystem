#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
#include "Vegetation.h"

class World {
	const int m_size;		// size of the playing grid
	Tile*** m_grid;		// the playing grid

public:
	// initializes the world
	// TODO: create vegetation and animals in the constructor
	World(int size);

	// delete the world
	~World();

	// returns the number of tiles on the grid
	int size();
};

#endif