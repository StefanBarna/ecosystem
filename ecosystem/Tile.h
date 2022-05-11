#ifndef TILE_H
#define TILE_H

class Tile {
protected:

public:
	// retrieves the derived Tile ID
	virtual int ID() const = 0;

	// updates the derived Tile
	virtual void update() const = 0;
};

#endif