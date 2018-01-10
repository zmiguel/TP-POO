#pragma once
#include "librarias.h"

class Elementos {

	int id;
	static int i;

	char denominacao;
	int x;
	int y;
	int idCor;
	int energia;
	int energiaInicial;
	int iteracao;
public:

	Elementos(int x, int y, char denominacao, int idCor, int energia, int energiaInicial, int iteracao);

	int getPosX();
	int getPosY();

	int getID();
	int getIDCor();
	int getEnergia();
	int getEnergiaInicial();
	char getDenom();

	void setPosX(int x);
	void setPosY(int y);
	void setEnergia(int e);

	void setId(int idE);

	void setEnergiaInicial(int eI);

	~Elementos();
};

