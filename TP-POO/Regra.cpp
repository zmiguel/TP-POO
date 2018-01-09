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


bool RegraPasseia::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis)
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



bool RegraComeMigalha::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis)
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


bool RegraFoge::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis){

	int id;

	for (Elementos* i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y) {
			id = i->getIDCor();
		}
	}

	for (Elementos* i : elem) {
		
		if (i->getDenom() != 'N' && i->getDenom() != 'M' && i->getIDCor() != id) {
		
			if (i->getPosX() <= *x + vis && i->getPosX() >= *x - vis && i->getPosY() <= *y + vis && i->getPosY() >= *y - vis) {
			
					return true;
			}
		}
	}
	return false;
}

void RegraFoge::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis) {

	int id;
	bool flag = false;

	for (Elementos* i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y) {
			id = i->getIDCor();
		}
	}

	for (Elementos* i : elem) {

		if (i->getDenom() != 'N' && i->getDenom() != 'M' && i->getIDCor() != id) {

			if (i->getPosX() <= *x + vis && i->getPosX() >= *x - vis && i->getPosY() <= *y + vis && i->getPosY() >= *y - vis) {
				
				int px = *x - i->getPosX();
				int py = *y - i->getPosY();

	
				if (px > 0 && py > 0) {
					//topesq
					while (mov > 0) {
						int tempX = *x + mov;
						int tempY = *y + mov;


						if (tempX > dim || tempY > dim) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = tempX + (rand() % (mov + 10) + (-mov));
								*y = tempX + (rand() % (mov + 10) + (-mov));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
								}
								else {
									*x = tempX;
									*y = tempY;
								}
							}
						}
					}
				}
			}
		}
	}
}

