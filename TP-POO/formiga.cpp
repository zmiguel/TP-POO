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

	oss << "\nFormiga ID: " << id
		<< " Energia: " << energia
		<< " Raio de Visao: " << raioMov
		<< " (" << posX << ","
		<< posY << ")";

	string s = oss.str();
	return s;
}
