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

public:

	Elementos(int x, int y, char denominacao, int idCor, int energia);

	int getPosX();
	int getPosY();

	int getID();
	int getIDCor();
	char getDenom();

	void setPosX(int x);
	void setPosY(int y);

	void setId(int idE);

	~Elementos();
};

