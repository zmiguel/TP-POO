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
		*cx++;
		*cy++;
		oss << it->getAsString() << endl;
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

			ninhos[id - 1].acrescentaFormiga(x, y, 150);
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

void Mundo::iteracao(int temp){

		for (unsigned int i = 0; i < ninhos.size(); i++) {
			for (int k = 0; k < ninhos[i].numFormigas(); k++) {
				regraPasseia(i, k);
			}
		}
}

void Mundo::regraPasseia(int idn, int idf) {

	bool flag = false;
	int x = 0;
	int y = 0;

	int xi = ninhos[idn].formigaPosX(idf); // Posição Inicial X
	int yi = ninhos[idn].formigaPosY(idf); // Posição Inicial Y

	int movX = ninhos[idn].formigaMov(idf); // RAIO DE MOVIMENTO (FORMIGA EXPLORADORA)
	int movY = ninhos[idn].formigaMov(idf); // RAIO DE MOVIMENTO (FORMIGA EXPLORADORA)

		while (flag == false) {
			x = xi + (rand() % (movX + 10) + (-movX));											//NOVA POSIÇÃO X = POSIÇÃO INICIAL + (NÚMERO RANDOM ENTRE RAIO DE VISÃO E - (RAIO DE VIÃO))
			y = yi + (rand() % (movY + 10) + (-movY));											//NOVA POSIÇÃO Y = POSIÇÃO INICIAL + (NÚMERO RANDOM ENTRE RAIO DE VISÃO E - (RAIO DE VIÃO))
			if (x >= 0 && x < getDim() && y >= 0 && y < getDim() && ocupaPos(x,y) == false) {	// NOVA POSIÇÃO É ACEITA SEGUNDO AS CONDIÇÕES
				flag = true;
				ninhos[idn].formigaSetX(idf, x);
				ninhos[idn].formigaSetY(idf, y);

				int movEX = x - xi;
				int movEY = y - yi;

				int energGasta = abs(movEX) + abs(movEY);
				int energInicial = ninhos[idn].formigaEnerg(idf);
				int energAtual = energInicial - energGasta;
				ninhos[idn].formigaSetEner(idf, energAtual);
			}
		}
}

Mundo::~Mundo()
{
}
