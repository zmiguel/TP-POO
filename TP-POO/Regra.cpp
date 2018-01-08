#include "Regra.h"

Regra::Regra(bool rule)
{
	this->regra = rule;

	/*/		
	C - RegraFoge														RegraComeMigalha	RegraProcuraMigalha		RegraVaiParaNinho	RegraPasseia
	V -					RegraProtege									RegraComeMigalha	RegraProcuraMigalha							RegraPasseia
	A -									RegraAssalta	RegraPersegue	RegraComeMigalha	RegraProcuraMigalha							RegraPasseia
	E -																	RegraComeMigalha												RegraPasseia
	/*/
}

bool Regra::getRegras(int i, int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis) {


	if (regra == true && i == 0) {
		return regraFoge();
	}
	else {
		if (regra == true && i == 1) {
			return regraProtege();
		}
		else {
			if (regra == true && i == 2) {
				return regraAssalta();
			}
			else {
				if(regra == true && i == 3){
					return regraPersegue();
				}
				else {
					if (regra == true && i == 4) {
						return regraComeMigalha();
					}
					else {
						if (regra == true && i == 5) {
							return regraProcuraMigalha();
						}
						else {
							if (regra == true && i == 6) {
								return regraVaiParaNinho();
							}
							else {
								if (regra == true && i == 7) {
									return regraPasseia(x, y, dim, elem, mov, vis);
								}
							}
						}
					}
				}
			}
		}
	}
}

bool Regra::ocupaPos(int x, int y, vector<Elementos*> elem) {

	for (unsigned int i = 0; i < elem.size(); i++) {
		if (elem[i]->getPosX() == x && elem[i]->getPosY() == y) {
			return true;
		}
	}

	return false;
}

bool Regra::regraPasseia(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis) {

	bool flag = false;

	int xi = *x; // Posi��o Inicial X
	int yi = *y;; // Posi��o Inicial Y

	while (flag == false) {
		
		*x = xi + (rand() % (mov + 10) + (-mov));											//NOVA POSI��O X = POSI��O INICIAL + (N�MERO RANDOM ENTRE RAIO DE VIS�O E - (RAIO DE VI�O))
		*y = yi + (rand() % (mov + 10) + (-mov));											//NOVA POSI��O Y = POSI��O INICIAL + (N�MERO RANDOM ENTRE RAIO DE VIS�O E - (RAIO DE VI�O))
		if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {									// NOVA POSI��O � ACEITA SEGUNDO AS CONDI��ES
			flag = true;
			return true;
		}
		else {
			*x = xi;
			*y = yi;
		}
	}

	return false;
}

bool Regra::regraFoge()
{
	return false;
}

bool Regra::regraProtege()
{
	return false;
}

bool Regra::regraAssalta()
{
	return false;
}

bool Regra::regraPersegue()
{
	return false;
}

bool Regra::regraComeMigalha()
{
	return false;
}

bool Regra::regraProcuraMigalha()
{
	return false;
}

bool Regra::regraVaiParaNinho()
{
	return false;
}

Regra::~Regra()
{
}