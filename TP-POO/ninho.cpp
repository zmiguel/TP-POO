#include "Ninho.h"

int Ninho::i = 1;

Ninho::Ninho(int x, int y, int energNinhos) {
	this->id = i++;
	this->PosX = x;
	this->PosY = y;
	this->energiaInicial = energNinhos;
}

int Ninho::getX() const {
	return PosX;
}

int Ninho::getY() const{
	return PosY;
}

string Ninho::getAsString()const {

	ostringstream oss;

	oss << "Ninho ID: " << id
		<< " Posicao: (" << PosX
		<< "," << PosY << ")"
		<< " Energia: "<< energiaInicial;


	for (unsigned int i = 0; i < formigas.size();i++) {
		oss << formigas[i]->getAsString();
	}

	oss << endl;

	return oss.str();
}

string Ninho::ninhoInfo() {

	ostringstream oss;

	oss << "Ninho com ID: " << id
		<< "\nPosicao: (" << PosX
		<< "," << PosY << ")"
		<< "\nEnergia Inicial de: " << energiaInicial << endl;

	return oss.str();

}

string Ninho::formigaInfo(int id) {

	return formigas[id]->getAsString();

}

void Ninho::acrescentaFormiga(int x, int y) {

		Formiga* ob = new Formiga(x, y);
		formigas.push_back(ob);
}

int Ninho::numFormigas() {

	return formigas.size();
}

int Ninho::formigaPosX(int id) {

	return formigas[id]->getX();
}

int Ninho::formigaPosY(int id) {

	return formigas[id]->getY();
}

void Ninho::formigaSetX(int id, int x) {

	formigas[id]->setX(x);
}

void Ninho::formigaSetY(int id, int y) {

	formigas[id]->setY(y);
}

int Ninho::formigaVisao(int id) {

	return formigas[id]->getVisao();
}

int Ninho::formigaMov(int id) {

	return formigas[id]->getMov();
}

Ninho::~Ninho(){

}
