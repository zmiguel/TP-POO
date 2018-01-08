#pragma once
#include "librarias.h"

class Migalha
{
	int id = 10;
	int energia;
	int PosX;
	int PosY;
	char denom = 'M';

public:
	Migalha(int x, int y, int e);
	int getId();
	int getPosX();
	int getPosY();
	int getEnergia();
	void setEnergia(int e);
	string getAsString();
	~Migalha();
};

