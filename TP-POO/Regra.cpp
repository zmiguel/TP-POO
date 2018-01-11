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
	cout << "[REGRA] Passeia" << endl;
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

	cout << "[REGRA] Come Migalha"<< endl;
	for (Elementos* i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y && i->getDenom() != 'N') {
			denom = i->getDenom();
			break;
		}
	}
	if (denom == 'C') {
		dentada = (float) 0.5;
	}

	if (denom == 'A') {
		dentada = (float) 0.25;
	}

	if (denom == 'V') {
		dentada = (float) 0.75;
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

	cout << "[REGRA] Procura Migalha" << endl;
	//vars para procurara mais energia
	int bestX = 0;
	int bestY = 0;
	int BestEnerg = 0;
	int movi = mov;

	bool flag = false;

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
		if (flag == true) {
			break;
		}

		if (bestX == i->getPosX() && bestY == i->getPosY()) {
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


			int px = i->getPosX() - *x;
			int py = i->getPosY() - *y;
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


bool RegraVaiParaNinho::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis) {

	bool flag = false;
	int id;

	for (Elementos * i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y)
			id = i->getIDCor();
	}

	for (Elementos * i : elem) {
		if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY()) == true && i->getDenom() == 'N' && i->getIDCor() == id) {
			flag = true;
		}
	}

	for (Elementos * i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y) {
			if (i->getEnergia() > i->getEnergiaInicial() || i->getEnergiaInicial() * 0.5 > i->getEnergia()) {
				if (i->getItt() > 10 && flag == true) {	
					return true;
				}
			}
		}
	}

	return false;
}

void RegraVaiParaNinho::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis) {

	bool flag = false;
	bool flag2 = false;
	int id;
	int xi = *x;
	int yi = *y;
	int movi = mov;
	cout << "[REGRA] Vai Para Ninho" << endl;

	for (Elementos * i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y)
			id = i->getIDCor();
	}

	for (Elementos * i : elem) {
		if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY()) == true && i->getDenom() == 'N' && i->getIDCor() == id) {
			flag2 = true;
		}
	}


	for (Elementos * i : elem) {
		if (flag == true) {
			break;
		}
		if (i->getPosX() == *x && i->getPosY() == *y) {
			if (i->getEnergia() > i->getEnergiaInicial() || i->getEnergiaInicial() * 0.5 > i->getEnergia()) {
				if (i->getItt() > 10 && flag2 == true) {
					
					for (Elementos * j : elem) {
						if (flag == true) {
							break;
						}
					
						if (estaVisao(xi,yi, vis, j->getPosX(), j->getPosY()) == true && j->getDenom() == 'N' && j->getIDCor() == id) {
							cout << "Vi o ninho!" << endl;
							if (estaMov(xi, yi, mov, j->getPosX(), j->getPosY()) == true) {
								*x = j->getPosX();
								*y = j->getPosY();
								cout << "estou a entrar no ninho!" << endl;
							}
							else {
								cout << "vou para o ninho!" << endl;
								int px = j->getPosX() - *x;
								int py = j->getPosY() - *y;
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
			}
		}
	}
}


bool RegraFoge::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis){

	int id=0;


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

	int id = -1;
	bool flag = false;
	int xi = *x;
	int yi = *y;
	int movi = mov;

	cout << "RF" << endl;
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


bool RegraProtege::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis) {

	bool flagF = false;
	bool flagE = false;
	int id;
	cout << "Cond Proteje!" << endl;

	for (Elementos *i : elem) {
		if (*x == i->getPosX() && *y == i->getPosY() && i->getDenom() != 'N') {
			id = i->getIDCor();
			break;
		}
	}

	for (Elementos *i : elem) {
		if (id == i->getIDCor() && (*x != i->getPosX() || *y != i->getPosY()) && i->getDenom() != 'N'  && i->getDenom() != 'M') {
			if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY())) {
				cout << "Amiga!" << endl;
				flagF = true;
				break;
			}
		}
	}

	for (Elementos *i : elem) {
		if (id != i->getIDCor() && (*x != i->getPosX() || *y != i->getPosY()) && i->getDenom() != 'N' && i->getDenom() != 'M') {
			if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY())) {
				cout << "Enimiga!" << endl;
				flagE = true;
				break;
			}
		}
	}

	if (flagF == true && flagE == true) {
		return true;
	}

	return false;
}

void RegraProtege::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis) {

	cout << "[REGRA] Protege"<< endl;
		
	bool flagF = false;
	bool flagE = false;
	bool flag = false;
	int id;

	int xi = *x;
	int yi = *y;
	int movi = mov;


	int xF;
	int yF;

	int xE;
	int yE;
	
	for (Elementos *i : elem) {
		if (*x == i->getPosX() && *y == i->getPosY() && i->getDenom() != 'N') {
			id = i->getIDCor();
		}
	}

	for (Elementos *i : elem) {
		if (id == i->getIDCor() && (*x != i->getPosX() || *y != i->getPosY()) && i->getDenom() != 'N'  && i->getDenom() != 'M') {
			if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY())) {
				flagF = true;
				xF = i->getPosX();
				yF = i->getPosY();
				break;
			}
		}
	}

	for (Elementos *i : elem) {
		if (id != i->getIDCor() && (*x != i->getPosX() || *y != i->getPosY()) && i->getDenom() != 'N' && i->getDenom() != 'M') {
			if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY())) {
				flagE = true;
				xE = i->getPosX();
				yE = i->getPosY();
				break;
			}
		}
	}

	if (flagF == true && flagE == true) {
		
		int posX = (int) round((xF + xE) / 2);
		int posY = (int) round((yF + yE) / 2);

		cout << "(INFO) " << posX << "," << posY << endl;

		if (posX == *x && posY == *y) {
			return;
		}

		if (estaMov(*x, *y, mov, posX, posY)) {
			if (ocupaPos(posX, posY, elem) == false) {
				*x = posX;
				*y = posY;
			}
			else {
				if (estaVisao(xi, yi, vis, posX + 1, posY) == true && ocupaPos(posX + 1, posY, elem) == false && estaMov(xi, yi, mov, posX + 1, posY) == true && posX + 1 < dim && posY < dim && posX + 1 >= 0 && posY >= 0) {
					*x = posX + 1;
					*y = posY;
				}
				if (estaVisao(xi, yi, vis, posX - 1, posY) == true && ocupaPos(posX - 1, posY, elem) == false && estaMov(xi, yi, mov, posX - 1, posY) == true && posX - 1 < dim && posY < dim && posX - 1 >= 0 && posY >= 0) {
					*x = posX - 1;
					*y = posY;
				}
				if (estaVisao(xi, yi, vis, posX, posY + 1) == true && ocupaPos(posX, posY + 1, elem) == false && estaMov(xi, yi, mov, posX, posY + 1) == true && posX < dim && posY + 1 < dim && posX >= 0 && posY + 1 >= 0) {
					*x = posX;
					*y = posY + 1;
				}
				if (estaVisao(xi, yi, vis, posX, posY - 1) == true && ocupaPos(posX, posY - 1, elem) == false && estaMov(xi, yi, mov, posX, posY - 1) == true && posX < dim && posY - 1 < dim && posX >= 0 && posY - 1 >= 0) {
					*x = posX;
					*y = posY - 1;
				}
			}
		}
		else {
		
			int px = posX - *x;
			int py = posY - *y;
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


bool RegraAssalta::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int mov) {
	
	int id;
	int ninhoX = -1;
	int ninhoY = -1;
	mov = mov / 2;

	cout << "Cond Assalta!" << endl;

	for (Elementos *i : elem) {
		if (*x == i->getPosX() && *y == i->getPosY() && i->getDenom() != 'N') {
			id = i->getIDCor();
			break;
		}
	}

	for (Elementos *i : elem) {
		if (i->getIDCor() != id && i->getDenom() != 'M') {
			if (i->getDenom() == 'N') {
				ninhoX = i->getPosX();
				ninhoY = i->getPosY();
			}
			else {
				if (estaMov(*x, *y, mov, i->getPosX(), i->getPosY()) && i->getPosX() != ninhoX && i->getPosY() != ninhoY) {
					return true;
				}
			}
		}
	}

	return false;

}

void RegraAssalta::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis) {

	int id;
	bool flag;
	int bestX = 0;
	int bestY = 0;
	int BestEnerg = 0;

	int ninhoX = -1;
	int ninhoY = -1;

	cout << "[REGRA] Assalta" << endl;

	for (Elementos *i : elem) {
		if (*x == i->getPosX() && *y == i->getPosY() && i->getDenom() != 'N') {
			id = i->getIDCor();
			break;
		}
	}

	for (Elementos* i : elem) {
		if (i->getIDCor() != id && i->getDenom() != 'M') {
			if (i->getDenom() == 'N') {
				ninhoX = i->getPosX();
				ninhoY = i->getPosY();
			}
			else {
				if (estaMov(*x, *y, mov, i->getPosX(), i->getPosY()) && i->getPosX() != ninhoX && i->getPosY() != ninhoY) {
					if (i->getPosX() <= *x + mov && i->getPosX() >= *x - mov && i->getPosY() <= *y + mov && i->getPosY() >= *y - mov) {
						if (i->getEnergia() > BestEnerg) {
							bestX = i->getPosX();
							bestY = i->getPosY();
							BestEnerg = i->getEnergia();
						}
					}
				}
			}
		}
	}


	for (Elementos *i : elem) {
		if (i->getPosX() == bestX && i->getPosY() == bestY) {
			i->setEnergia(i->getEnergia() * 0.5);
			break;
		}
	}

	for (Elementos *i : elem) {
		if (i->getPosX() == *x && i->getPosY() == *y) {
			i->setEnergia(i->getEnergia() + (BestEnerg * 0.5));
			break;
		}
	}
}


bool RegraPersegue::condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis) {


	int id;
	int ninhoX = -1;
	int ninhoY = -1;

	cout << "Cond Persegue!" << endl;

	for (Elementos *i : elem) {
		if (*x == i->getPosX() && *y == i->getPosY() && i->getDenom() != 'N') {
			id = i->getIDCor();
			break;
		}
	}

	for (Elementos *i : elem) {
		if (i->getIDCor() != id && i->getDenom() != 'M') {
			if (i->getDenom() == 'N') {
				ninhoX = i->getPosX();
				ninhoY = i->getPosY();
			}
			else {
				if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY()) && i->getPosX() != ninhoX && i->getPosY() != ninhoY) {
					return true;
				}
			}
		}
	}
	return false;
}

void RegraPersegue::acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis) {

	int id;
	bool flag = false;
	int bestX = 0;
	int bestY = 0;
	int BestEnerg = 0;
	int movi = mov;
	int xi = *x;
	int yi = *y;

	int ninhoX = -1;
	int ninhoY = -1;

	cout << "[REGRA] Persegue" << endl;

	for (Elementos *i : elem) {
		if (*x == i->getPosX() && *y == i->getPosY() && i->getDenom() != 'N') {
			id = i->getIDCor();
			break;
		}
	}

	for (Elementos* i : elem) {
		if (i->getIDCor() != id && i->getDenom() != 'M') {
			if (i->getDenom() == 'N') {
				ninhoX = i->getPosX();
				ninhoY = i->getPosY();
			}
			else {
				if (estaVisao(*x, *y, vis, i->getPosX(), i->getPosY()) && i->getPosX() != ninhoX && i->getPosY() != ninhoY) {
					if (i->getPosX() <= *x + mov && i->getPosX() >= *x - mov && i->getPosY() <= *y + mov && i->getPosY() >= *y - mov) {
						if (i->getEnergia() > BestEnerg) {
							bestX = i->getPosX();
							bestY = i->getPosY();
							BestEnerg = i->getEnergia();
						}
					}
				}
			}
		}
	}
	cout << "best " << bestX << " " << bestY << endl;

	for (Elementos* i : elem) {
		if (flag == true) {
			break;
		}

		if (bestX == i->getPosX() && bestY == i->getPosY()) {
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


			int px = bestX - xi;
			int py = bestY - yi;
			cout << "px py" << px << " " << py << endl;


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
