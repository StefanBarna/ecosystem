#ifndef GRASS_H
#define GRASS_H

#include "Vegetation.h"

class Grass : public Vegetation {
	static int m_ID;		// ID of grass

	static int m_spawn;		// chance of spawning on a random Tile
	static int m_spread;	// chance of spawning on a neigboring Tile

	static int m_span;		// lifespan before decay
	static int m_decay;		// rate of decay

public:
	// base constructor
	Grass();

	// retrieves the derived Tile ID
	int ID() const;

	// updates the derived Tile
	void update();

	// retrieve percent chance to spawn on a random tile
	int spawnRate() const;

	// retrieve percent chance to spread to a neighboring tile
	int spreadRate() const;

	// retrieve minimum lifespan while uninteracted
	int lifespan() const;

	// retrieve rate at which the plant decays after lifespan
	int decayRate() const;
};

#endif