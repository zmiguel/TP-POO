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
	string formigaInfo(int id);
	string ninhoInfo();

	int getX()const;
	int  getY()const;

	int formigaPosX(int id);
	int formigaPosY(int id);
	int numFormigas();
	void acrescentaFormiga(int x, int y);

	Ninho(int x, int y, int energiaInicial);
	~Ninho();
};

