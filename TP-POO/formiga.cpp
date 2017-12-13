#include "Formiga.h"

int Formiga::i = 1;

Formiga::Formiga(int x, int y):posX(x), posY(y){
	this->id = i++;
}

int Formiga::getX() const{

	return posX;
}

int Formiga::getY() const{

	return posY;
}

int Formiga::getVisao() {

	return raioVisao;
}

int Formiga::getMov() {

	return raioMov;
}

void Formiga::setX(int x) {

	posX = x;
}

void Formiga::setY(int y) {

	posY = y;
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
