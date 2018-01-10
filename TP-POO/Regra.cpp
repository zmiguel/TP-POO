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

bool Regra::estaVisao(int x, int y, int vis, int xp, int yp) {
	int xmax = x + vis;
	int xmim = x - vis;
	int ymax = y + vis;
	int ymim = y - vis;
	if (xp >= xmim && xp <= xmax && yp >= ymim && yp <= ymax) {
		return true;
	}
	else {
		return false;
	}
}

bool Regra::estaMov(int x, int y, int mov, int xp, int yp) {
	int xmax = x + mov;
	int xmim = x - mov;
	int ymax = y + mov;
	int ymim = y - mov;
	if (xp >= xmim && xp <= xmax && yp >= ymim && yp <= ymax) {
		return true;
	}
	else {
		return false;
	}
}


bool RegraPasseia::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis)
{
	return true;
}

void RegraPasseia::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis)
{
	bool flag = false;

	int xi = *x;
	int yi = *y;

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


bool RegraProcuraMigalha::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis)
{
	for (Elementos* i : elem) {
		if (i->getDenom() == 'M') {
			if (i->getPosX() <= *x + vis && i->getPosX() >= *x - vis && i->getPosY() <= *y + vis && i->getPosY() >= *y - vis) {
				return true;
			}
		}
	}
	return false;
}

void RegraProcuraMigalha::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis) {

	int xi = *x;
	int yi = *y;

	//vars para procurara mais energia
	int bestX = 0;
	int bestY = 0;
	int BestEnerg = 0;

	for (Elementos* i : elem) {
		if (i->getDenom() == 'M') {
			if (i->getPosX() <= *x + vis && i->getPosX() >= *x - vis && i->getPosY() <= *y + vis && i->getPosY() >= *y - vis) {
				if (i->getEnergia() > BestEnerg) {
					bestX = i->getPosX();
					bestY = i->getPosY();
					BestEnerg = i->getEnergia();
				}
			}
		}
	}
	for (Elementos* i : elem) {
		if (bestX == i->getPosX() && bestY == i->getPosY()) {
			cout << "encontrei a melhor\n";
			if (estaVisao(xi, yi, vis, bestX + 1, bestY) == true && ocupaPos(bestX + 1, bestY, elem) == false && estaMov(xi, yi, mov, bestX + 1, bestY) == true && bestX + 1 < dim && bestY < dim && bestX + 1 >= 0 && bestY >= 0) {
				*x = bestX + 1;
				*y = bestY;
				break;
			}
			if (estaVisao(xi, yi, vis, bestX - 1, bestY) == true && ocupaPos(bestX - 1, bestY, elem) == false && estaMov(xi, yi, mov, bestX - 1, bestY) == true && bestX - 1 < dim && bestY < dim && bestX - 1 >= 0 && bestY >= 0) {
				*x = bestX - 1;
				*y = bestY;
				break;
			}
			if (estaVisao(xi, yi, vis, bestX, bestY + 1) == true && ocupaPos(bestX, bestY + 1, elem) == false && estaMov(xi, yi, mov, bestX, bestY + 1) == true && bestX < dim && bestY + 1 < dim && bestX >= 0 && bestY + 1 >= 0) {
				*x = bestX;
				*y = bestY + 1;
				break;
			}
			if (estaVisao(xi, yi, vis, bestX, bestY - 1) == true && ocupaPos(bestX, bestY - 1, elem) == false && estaMov(xi, yi, mov, bestX, bestY - 1) == true && bestX < dim && bestY - 1 < dim && bestX >= 0 && bestY - 1 >= 0) {
				*x = bestX;
				*y = bestY - 1;
				break;
			}

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
	int xi = *x;
	int yi = *y;
	int movi = mov;


	for (Elementos* i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y) {
			id = i->getIDCor();
		}
	}

	for (Elementos* i : elem) {
		if (flag == true) {
			break;
		}

		if (i->getDenom() != 'N' && i->getDenom() != 'M' && i->getIDCor() != id) {

			if (i->getPosX() <= *x + vis && i->getPosX() >= *x - vis && i->getPosY() <= *y + vis && i->getPosY() >= *y - vis) {
				
				int px = *x - i->getPosX();
				int py = *y - i->getPosY();
				cout << px << ", " << py << endl;

	
				if (px > 0 && py > 0) {
					//topesq
					while (mov > 0) {
						int tempX = *x + mov;
						int tempY = *y + mov;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
				else if (px > 0 && py < 0) {
					//baixoesq
					while (mov > 0) {
						int tempX = *x + mov;
						int tempY = *y - mov;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
				else if (px < 0 && py > 0) {
					//topdir
					while (mov > 0) {
						int tempX = *x - mov;
						int tempY = *y + mov;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
				else if (px < 0 && py < 0) {
					//baixodir
					while (mov > 0) {
						int tempX = *x - mov;
						int tempY = *y - mov;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
				else if (px == 0 && py > 0) {
					//cima
					while (mov > 0) {
						int tempX = *x;
						int tempY = *y + mov;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
				else if (px == 0 && py < 0) {
					//baixo
					while (mov > 0) {
						int tempX = *x;
						int tempY = *y - mov;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
				else if (px > 0 && py == 0) {
					//esquerda
					while (mov > 0) {
						int tempX = *x + mov;
						int tempY = *y;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
				else if (px < 0 && py == 0) {
					//direita
					while (mov > 0) {
						int tempX = *x - mov;
						int tempY = *y;


						if (tempX >= dim || tempY >= dim || tempX < 0 || tempY < 0) {
							mov--;
						}
						else {
							if (ocupaPos(tempX, tempY, elem) == false) {
								*x = tempX;
								*y = tempY;
								flag = true;
								break;
							}
							else {
								mov--;
							}
						}

						if (mov == 0)
						{
							while (flag == false) {
								*x = xi + (rand() % (movi + 10) + (-movi));
								*y = yi + (rand() % (movi + 10) + (-movi));
								if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {
									flag = true;
									break;
								}
								else {
									*x = xi;
									*y = yi;
								}
							}
						}
						if (flag == true) {
							break;
						}
					}
				}
			}
		}
	}
}

