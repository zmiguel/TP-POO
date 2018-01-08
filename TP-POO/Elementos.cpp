#include "Elementos.h"

int Elementos::i = 1;

Elementos::Elementos(int x, int y, char denominacao, int idCor) {

	this->denominacao = denominacao;
	this->x = x;
	this->y = y;
	this->idCor = idCor;
	this->id = i++;

}

int Elementos::getPosX() {

	return x;
}

int Elementos::getPosY() {

	return y;
}

int Elementos::getID() {
	return id;
}

int Elementos::getIDCor() {
	return idCor;
}

char Elementos::getDenom() {

	return denominacao;
}

void Elementos::setPosX(int xi)
{
	x = xi;
}

void Elementos::setPosY(int yi)
{
	y = yi;
}

void Elementos::setId(int idE) {
	id = idE;
}

Elementos::~Elementos()
{
}
