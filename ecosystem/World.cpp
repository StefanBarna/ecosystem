#include <random>
#include <Windows.h> // TODO: also temporary for the same reason as below
#include <iostream>	// TODO: this is here temporarily; lateron this class should not deal with view, as it is part of the model
#include "World.h"
#include "Grass.h"

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

	// generate grass clusters
	int seeds = 0.2 * this->size();
	int cores = 0.05 * this->size();
	int* cluster = new int[cores];
	std::random_device engine;
	std::uniform_int_distribution<int> randomCore(0, cores - 1);
	for (int i = 0; i < cores; ++i) {
		cluster[i] = 0;
	}
	
	for (int i = 0; i < seeds; ++i) {
		cluster[randomCore(engine)]++;
	}

	// place grass clusters
	std::uniform_int_distribution<int> randomSeed(0, this->m_size - 1);
	int randx,
		randy;
	bool resume = true;

	// TODO: create the grass locations based on clusters rather than just pure random

	for (int i = 0; i < seeds; i++) {
		do {
			randx = randomSeed(engine);
			randy = randomSeed(engine);
			if (this->m_grid[randx][randy] == nullptr) {
				this->m_grid[randx][randy] = new Grass();
				resume = true;
			}
			else
				resume = false;
		} while (!resume);
	}

	delete[] cluster;

	// display
	// TODO: enable double buffering
	std::cout << u8"┌";
	for (int i = 0; i < this->m_size * 2; ++i) {
		std::cout << u8"─";
	}
	std::cout << u8"┐" << std::endl;
	for (int i = 0; i < this->m_size; ++i) {
		std::cout << u8"│";
		for (int j = 0; j < this->m_size; ++j) {
			if (this->m_grid[i][j] == nullptr)
				std::cout << u8"·";
			else
				std::cout << u8"⬜";
			std::cout << " ";
		}
		std::cout << u8"│" << std::endl;
	}
	std::cout << u8"└";
	for (int i = 0; i < this->m_size * 2; ++i) {
		std::cout << u8"─";
	}
	std::cout << u8"┘" << std::endl;
}

World::~World() {
	for (int i = 0; i < this->m_size; ++i) {
		delete[] this->m_grid[i];
	}
	delete[] this->m_grid;
}

int World::size() {
	return this->m_size * this->m_size;
}

int main() {
	// sets the console to UTF8
	SetConsoleOutputCP(CP_UTF8);

	World* w = new World(10);
	

	delete w;
}