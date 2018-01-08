#include "Ninho.h"

int Ninho::i = 1;

Ninho::Ninho(int x, int y, int energNinhos) {
	this->id = i++;
	this->PosX = x;
	this->PosY = y;
	this->energiaInicial = energNinhos;
	this->energia = energNinhos;
}

//------------GET'S & SET'S (NINHO)------------//

int Ninho::getX() const {
	return PosX;
}

int Ninho::getY() const{
	return PosY;
}

int Ninho::getID() const {
	return id;
}

int Ninho::numFormigas() {
	return formigas.size();
}

char Ninho::getDenom() {
	return denom;
}

string Ninho::ninhoInfo() const {

	ostringstream oss;

	oss << "Ninho ID: " << id
		<< " Posicao: (" << PosX
		<< "," << PosY << ")"
		<< " Energia: " << energiaInicial
		<< "\nNúmero de formigas do ninho:  " << formigas.size()
		<< endl;

	return oss.str();
}

void Ninho::setID(int id) {
	id = i;
}

int Ninho::getEnergia() {

	return energia;
}

void Ninho::setEnergia(int e) {

	energia = e;
}


//------------GET'S & SET'S (FORMIGA)------------//

int Ninho::getFormigaDenom(int id)
{
	return formigas[id]->getDenom();
}

string Ninho::getAsString()const {

	ostringstream oss;

	oss << "Ninho ID: " << id
		<< " Posicao: (" << PosX
		<< "," << PosY << ")"
		<< " Energia: "<< energia;

	for (unsigned int i = 0; i < formigas.size();i++) {
		oss << formigas[i]->getAsString();
	}

	oss << endl;

	return oss.str();
}

string Ninho::formigaInfo(int id) {
	return formigas[id]->getAsString();
}

void Ninho::formigaSetIdNinho(int n) {

	for (int i = 0; i < formigas.size(); i++) {
		formigas[i]->setIdNinho(n);
	}
	
}

void Ninho::setPosVetor(int pos) {
	posVetor = pos;
}

int Ninho::getPosVetor() {

	return posVetor;
}

//-------------FORMIGAS (GETS & SETS)------------------//

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

int Ninho::getIDNinho(int idF) {

	return formigas[idF-1]->getIdNinho();
}

int Ninho::suaFormigaPos(int x, int y) {

	int conta= 0;

	for (unsigned int i = 0; i < formigas.size(); i++) {
		if (formigas[i]->getX() == x && formigas[i]->getY() == y) {
			return conta;
		}
		conta++;
	}
	return -1;
}



//-------------FORMIGAS------------------//


void Ninho::acrescentaFormiga(int x, int y, char c, int idN) {

	Formiga* formiga1 = new Exploradora(x, y, c);

	formiga1->setEnerInicial(200);
	formiga1->setMov(8);
	formiga1->setVisao(10);
	formiga1->setIdNinho(idN);
	formiga1->preencheRegras();
	formigas.push_back(formiga1);
}

void Ninho::regras(int idF, int dim, vector <Elementos*> elem) {

	formigas[idF]->regrasPercorre(dim, elem, formigas[idF]->getX(), formigas[idF]->getY(), idF);

	if (formigas[idF]->getEner() <= 0) {
		mataFormiga(idF);
	}
}

void Ninho::mataFormiga(int id) {

	delete formigas[id];
	formigas.erase(formigas.begin() + id);
}

void Ninho::assassinaProcura(int x, int y) {

	for (unsigned int i = 0; i < formigas.size(); i++) {
		if (formigas[i]->getX() == x && formigas[i]->getY() == y) {
			delete formigas[i];
			formigas.erase(formigas.begin() + i);
		}
	}
}

Ninho::~Ninho(){

}
