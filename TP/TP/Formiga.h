#pragma once
#include "librarias.h"

class Formiga {

	int id;
	static int i;
	int energia = 200;
	int raioVisao = 10;
	int raioMov = 8;

	int posX;
	int posY;
public:
	Formiga(int x, int y);
	int getX()const;
	int  getY()const;
	string getAsString();
};

