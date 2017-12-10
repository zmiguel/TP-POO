#pragma once
#include "librarias.h"

class Formiga;

class Ninho{
	int id;
	static int i;
	int energiaInicial;
	int perFazNovoNinho;
	int transFormNin;
	int PosX;
	int PosY;
	vector<Formiga*> formigas;
public:
	string getAsString()const;
	int getX()const;
	int  getY()const;

	void acrescentaFormiga();

	Ninho(int x, int y);
	~Ninho();
};

