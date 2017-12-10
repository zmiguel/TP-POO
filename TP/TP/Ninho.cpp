#include "Ninho.h"

int Ninho::i = 1;

Ninho::Ninho(int x, int y) {
	this->id = i++;
	this->PosX = x;
	this->PosY = y;
}


int Ninho::getX() const {
	return PosX;
}

int Ninho::getY() const{
	return PosY;
}


string Ninho::getAsString()const {

	ostringstream oss;

	oss << "Ninho com ID: " << id
		<< "\nPosicao: (" << PosX
		<< "," << PosY << ")" 
		<< endl;

	return oss.str();
}

void Ninho::acrescentaFormiga() {


}



Ninho::~Ninho()
{
}
