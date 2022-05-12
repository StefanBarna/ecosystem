#ifndef TILE_H
#define TILE_H

class Tile {
protected:
	// TODO: pointer to what animal this tile holds
	// TODO: variable suggesting whether or not an animal can be on this tile

public:
	// retrieves the derived Tile ID
	virtual int ID() const = 0;

	// updates the derived Tile
	virtual void update() = 0;
};

#endif