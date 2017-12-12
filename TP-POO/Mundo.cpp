#include "Mundo.h"

Mundo::Mundo(int dim, int energNinhos, int perFazNovoNinho, int transFormNin, int numPosMigalhas, int energiaInicialMig, int migalhaSorteio) :dimensao(dim){

	this->energNinhos = energNinhos;
	this->perFazNovoNinho = perFazNovoNinho;
	this->transFormNin = transFormNin;
	this->numPosMigalhas = numPosMigalhas;
	this->energiaInicialMig = energiaInicialMig;
	this->migalhaSorteio = migalhaSorteio;
}

int Mundo::getDim() const{
	return dimensao;
}

void Mundo::setDim(int dim) {
	dimensao = dim;
}

void Mundo::imprime(){

	int flag = 0;
	int x = 65;
	int y = 5;
	int xi = 65;
	int yi = 5;


	cout << ninhos.size();

	while (x < getDim() + xi && y < getDim() + yi) {
		Consola::gotoxy(x, y);
		flag = 0;

		for (unsigned int i = 0; i < ninhos.size(); i++) {
			if (ninhos[i].getX() + xi == x && ninhos[i].getY() + yi == y) {
				cout << "N";
				flag = 1;
			}
		}

		for (unsigned int i = 0; i < ninhos.size(); i++) {
			for (int k = 0; k < ninhos[i].numFormigas(); k++) {
				if (formigaPosX(k) + xi == x && formigaPosY(k) + yi == y) {
					cout << "E";
					flag = 1;
				}
			} ////// CONFUSO
		}


		if (flag == 0) {
			cout << "*";
		}

		if (x - xi == getDim() - 1) {
			x = xi - 1;
			y++;
		}
		x++;
	}
}

void Mundo::acrescentaNinho(int x, int y){
	
	ninhos.push_back(Ninho(x, y, energNinhos));

}

string Mundo::getAsString(int *x, int *y) const{

	ostringstream oss;
	for (vector<Ninho>::const_iterator it = ninhos.begin(); it != ninhos.end(); it++) {
		oss << it->getAsString() << endl;
		*x = *x + 3;
		*y = *y + 3;
	}
	return oss.str();
}

string Mundo::listaNinho(int id) {

	ostringstream oss;
	
	for (unsigned int i = 0; i < ninhos.size(); i++) {
		if (id == i + 1) {
			oss << ninhos[i].getAsString();
		}
	}

	return oss.str();
}

int Mundo::numNinhos() {

	return ninhos.size();

}

void Mundo::formiga(int qnts, int id){
	
	int dim = getDim();
	ninhos[id-1].acrescentaFormiga(qnts, dim);

}

int Mundo::formigaPosX(int id) {
	
	int x = ninhos[id].formigaPosX();

	return x;
}

int Mundo::formigaPosY(int id) {

	int y = ninhos[id].formigaPosY();

	return y;
}

Mundo::~Mundo()
{
}
