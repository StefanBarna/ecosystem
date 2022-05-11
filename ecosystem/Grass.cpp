#include <random>
#include "Grass.h"

int Grass::m_ID = 100;
int Grass::m_spawn = 20;
int Grass::m_spread = 1;
int Grass::m_span = 10;
int Grass::m_decay = 20;

int Grass::ID() {
	return this->m_ID;
}

void Grass::update() {
	this->age();
	// TODO: implement decay and destruction
	/*if (this->getAge() > this->lifespan()) {

	}*/
}

int Grass::spawnRate() {
	return this->m_spawn;
}