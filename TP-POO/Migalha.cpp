#include "Migalha.h"

Migalha::Migalha(int x, int y, int e)
{	
	this->PosX = x;
	this->PosY = y;
	this->energia = e;
}

int Migalha::getId() {

	return id;
}

int Migalha::getPosX() {
	return PosX;
}

int Migalha::getPosY() {
	return PosY;
}

int Migalha::getEnergia() {
	return energia;
}

void Migalha::setEnergia(int e) {
	energia = e;
}

string Migalha::getAsString() {

	ostringstream oss;

	oss << "Migalha com energia: " << energia
		<< " X: " << PosX << " Y: " << PosY;

	return oss.str();
}

Migalha::~Migalha()
{
}
