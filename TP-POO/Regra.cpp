#include "Regra.h"

Regra::~Regra()
{
}

Regra::Regra()
{
}

bool Regra::ocupaPos(int x, int y, vector<Elementos*> elem) {

	for (unsigned int i = 0; i < elem.size(); i++) {
		if (elem[i]->getPosX() == x && elem[i]->getPosY() == y) {
			return true;
		}
	}

	return false;
}


bool RegraPasseia::condicao(int * x, int * y, int dim, vector<Elementos*> elem)
{
	return true;
}

void RegraPasseia::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis)
{
	bool flag = false;

	int xi = *x;
	int yi = *y;;

	while (flag == false) {

		*x = xi + (rand() % (mov + 10) + (-mov));
		*y = yi + (rand() % (mov + 10) + (-mov));
		if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
			flag = true;
		}
		else {
			*x = xi;
			*y = yi;
		}
	}
}



bool RegraComeMigalha::condicao(int * x, int * y, int dim, vector<Elementos*> elem)
{
	for (Elementos* i : elem) {

		if (i->getDenom() == 'M' && (i->getPosX() == *x - 1 && i->getPosY() == *y)) {
			return true;
		}

		if (i->getDenom() == 'M' && (i->getPosX() == *x + 1 && i->getPosY() == *y)) {
			return true;
		}

		if (i->getDenom() == 'M' && (i->getPosX() == *x && i->getPosY() == *y - 1)) {
			return true;
		}

		if (i->getDenom() == 'M' && (i->getPosX() == *x && i->getPosY() == *y + 1)) {
			return true;
		}

	}

	return false;
}

void RegraComeMigalha::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis){
	
	char denom;
	float dentada;
	int energiaInicial;
	int energia;

	for (Elementos* i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y) {
			denom = i->getDenom();
			break;
		}
	}

	if (denom == 'C') {
		dentada = 0.5;
	}

	if (denom == 'A') {
		dentada = 0.25;
	}

	if (denom == 'V') {
		dentada = 0.75;
	}

	if (denom == 'E') {
		dentada = (float) 0.6;
	}


	for (Elementos* i : elem) {

		if (i->getDenom() == 'M' && (i->getPosX() == *x - 1 && i->getPosY() == *y)) {
			energiaInicial = i->getEnergia();
			energia = (int) round(energiaInicial * (1 - dentada));
			i->setEnergia(energia);
			break;
		}

		if (i->getDenom() == 'M' && (i->getPosX() == *x + 1 && i->getPosY() == *y)) {
			energiaInicial = i->getEnergia();
			energia = (int)round(energiaInicial * (1 - dentada));
			i->setEnergia(energia);
			break;
		}

		if (i->getDenom() == 'M' && (i->getPosX() == *x && i->getPosY() == *y - 1)) {
			energiaInicial = i->getEnergia();
			energia = (int)round(energiaInicial * (1 - dentada));
			i->setEnergia(energia);
			break;
		}

		if (i->getDenom() == 'M' && (i->getPosX() == *x && i->getPosY() == *y + 1)) {
			energiaInicial = i->getEnergia();
			energia = (int)round(energiaInicial * (1 - dentada));
			i->setEnergia(energia);
			break;
		}

		
	}
			
	for (Elementos* i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y) {
			energia = energiaInicial - energia + (i->getEnergia());
			i->setEnergia(energia);
			break;
		}
	}
}
