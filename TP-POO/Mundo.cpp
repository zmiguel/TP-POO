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
				if (ninhos[i].formigaPosX(k) + xi == x && ninhos[i].formigaPosY(k) + yi == y) {
					cout << "E";
					flag = 1;
				}
			}
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

void Mundo::acrescentaNinho(int x, int y, int *cx, int *cy){
	
	if (ocupaPos(x, y) == false) {
		ninhos.push_back(Ninho(x, y, energNinhos));
		*cx = *cx + 2;
		*cy = *cy + 2;
	}
	else {
		cout << "\n Foi tentado ser criado um ninho numa posição já ocupada!";
		*cx = *cx + 4;
		*cy = *cy + 4;

	}
}

string Mundo::getAsString(int *cx, int *cy) const{

	ostringstream oss;
	for (vector<Ninho>::const_iterator it = ninhos.begin(); it != ninhos.end(); it++) {
		oss << it->getAsString() << endl;
		*cx = *cx + 3;
		*cy = *cy + 3;
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

void Mundo::trataFormiga(int qnts, int id) {

	int dim = getDim();
	int x;
	int y;

	while (qnts != 0) {
		x = rand() % dim;
		y = rand() % dim;

		if (ocupaPos(x, y) == false) {

			ninhos[id - 1].acrescentaFormiga(x, y);
			qnts--;
		}
	};
}

bool Mundo::ocupaPos(int x, int y) {

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		if (ninhos[i].getX() == x && ninhos[i].getY() == y) {
			return true;
		}
	}

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		for (int k = 0; k < ninhos[i].numFormigas(); k++) {
			if (ninhos[i].formigaPosX(k) == x && ninhos[i].formigaPosY(k) == y) {
				return true;
			}
		}
	}

	return false;
}

string Mundo::listaPos(int x, int y) {

	ostringstream oss;

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		if (ninhos[i].getX() == x && ninhos[i].getY() == y) {
			oss << ninhos[i].ninhoInfo();
		}
	}

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		for (int k = 0; k < ninhos[i].numFormigas(); k++) {
			if (ninhos[i].formigaPosX(k) == x && ninhos[i].formigaPosY(k) == y) {
				oss << ninhos[i].formigaInfo(k);
			}
		}
	}

	return oss.str();
}

void Mundo::iteracao(int temp){

	int x = 0;
	int y = 0;

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		for (int k = 0; k < ninhos[i].numFormigas(); k++) {
			if (ninhos[i].formigaPosX(k) == x && ninhos[i].formigaPosY(k) == y ) {
				
				


				if (ocupaPos(x, y) == false) {
					cout << "IN PROGRESS";
				}


			}
		}
	}

}

Mundo::~Mundo()
{
}
