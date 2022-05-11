#ifndef VEGETATION_H
#define VEGETATION_H

#include "Tile.h"

class Vegetation : public Tile {
protected:
	int m_age;	// time the Tile has existed

public:
	// retrieve percent chance to spawn on a random tile
	virtual int spawnRate() const = 0;

	// retrieve percent chance to spread to a neighboring tile
	virtual int spreadRate() const = 0;

	// retrieve minimum lifespan while uninteracted
	virtual int lifespan() const = 0;

	// retrieve rate at which the plant decays after lifespan
	virtual int decayRate() const = 0;

	// retrieves the duration in which the Vegetation has existed
	int getAge() { return this->m_age; };

	// updates the time the Vegetation has existed
	void age() { ++this->m_age; }
};

#endif