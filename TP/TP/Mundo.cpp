#include "Mundo.h"

Mundo::Mundo(int dim, int numNinhos, int perFazNovoNinho, int transFormNin, int numPosMigalhas, int energiaInicialMig, int migalhaSorteio) :dimensao(dim){

	this->numNinhos = numNinhos;
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

	int conta = 0;
	int flag = 0;
	int x = 65;
	int y = 5;
	int xi = 65;
	int yi = 5;

	while (x < getDim() + xi && y < getDim() + yi) {
		Consola::gotoxy(x, y);
		flag = 0;

		for (vector<Ninho>::const_iterator it = ninhos.begin(); it != ninhos.end(); it++) {
			if (it->getX() + xi == x && it->getY() + yi == y) {
				cout << "N";
				flag = 1;
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

void Mundo::acrescentaNinho(int x, int y){
	
	ninhos.push_back(Ninho(x, y));

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

void Mundo::criaNinhos(){
	int x;
	int y;

	for (int i = 0; i < numNinhos; i++) {
		x = rand() % dimensao;
		y = rand() % dimensao;

		ninhos.push_back(Ninho(x,y));			// em falta --> condição para que não existam ninhos sobrepostos
	}
}

Mundo::~Mundo()
{
}
