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

int Ninho::getID() const {
	return id;
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

string Ninho::ninhoInfo() const{

	ostringstream oss;

	oss << "Ninho ID: " << id
		<< " Posicao: (" << PosX
		<< "," << PosY << ")"
		<< " Energia: " << energiaInicial
		<< "\nNúmero de formigas do ninho:  " << formigas.size()
		<< endl;

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

int Ninho::formigaEnerg(int id) {

	return formigas[id]->getEner();
}

void Ninho::formigaSetEner(int id, int e) {

	formigas[id]->setEner(e);
}

void Ninho::mataFormiga(int id) {
	delete formigas[id];
	formigas.erase(formigas.begin() + id);
}

Ninho::~Ninho(){

}
