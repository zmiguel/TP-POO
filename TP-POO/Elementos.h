#pragma once
#include "librarias.h"

class Elementos {

	int id;
	static int i;

	char denominacao;
	int x;
	int y;
	int idCor;

public:

	int getPosX();
	int getPosY();

	int getID();
	int getIDCor();
	char getDenom();

	void setPosX(int x);
	void setPosY(int y);

	void setId(int idE);

	Elementos(int x, int y, char denominacao, int idCor);
	~Elementos();
};

