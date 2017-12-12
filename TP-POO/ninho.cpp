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

	oss << "Ninho com ID: " << id
		<< "\nPosicao: (" << PosX
		<< "," << PosY << ")"
		<< "\nEnergia Inicial de: "<< energiaInicial << endl;

	for (unsigned int i = 0; i < formigas.size();i++) {
		oss << formigas[i]->getAsString() << endl;
	}

	return oss.str();
}

void Ninho::acrescentaFormiga(int num, int dim) {

	int x;
	int y;

	// função para que as formigas criadas não se sobreponham a nada

	for (int i = 0; i < num; i++) {

		x = rand() % dim;
		y = rand() % dim;

		Formiga* ob = new Formiga(x, y);
		formigas.push_back(ob);
	}
}

int Ninho::numFormigas() {

	return formigas.size();
}

int Ninho::formigaPosX() {



}

int Ninho::formigaPosY() {


}

Ninho::~Ninho(){

}
