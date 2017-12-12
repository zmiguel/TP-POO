#include "Formiga.h"

int Formiga::i = 1;

Formiga::Formiga(int x, int y){
	this->id = i++;
	this->posX = x;
	this->posY = y;
	//cout << getAsString();
}

int Formiga::getX() const{

	return posX;
}

int Formiga::getY() const{

	return posY;
}

string Formiga::getAsString() {
	ostringstream oss;

	oss << "\nID: " << id
		<< "\nEnergia" << energia
		<< "\nRaio de Visao" << raioMov
		<< "\nX: " << posX
		<< "\nY: " << posY << endl;

	string s = oss.str();
	return s;
}
