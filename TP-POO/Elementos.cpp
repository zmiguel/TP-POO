#include "Elementos.h"

int Elementos::i = 1;

Elementos::Elementos(int x, int y, char denominacao, int idCor, int energia, int energiaInicial, int it) {

	this->denominacao = denominacao;
	this->x = x;
	this->y = y;
	this->idCor = idCor;
	this->energia = energia;
	this->energiaInicial = energiaInicial;
	this->id = i++;
	this->iteracao = it;
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

int Elementos::getEnergia()
{
	return energia;
}

int Elementos::getEnergiaInicial() {
	
	return energiaInicial;
}

int Elementos::getItt() {
	return iteracao;
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

void Elementos::setEnergia(int e)
{
	energia = e;
}

void Elementos::setId(int idE) {
	id = idE;
}



void Elementos::setEnergiaInicial(int eI) {

	energiaInicial = eI;

}

Elementos::~Elementos()
{
}
