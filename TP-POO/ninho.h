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
	string ninhoInfo() const;

	int getX()const;
	int getY()const;
	int getID()const;

	void formigaSetX(int id, int x);
	void formigaSetY(int id, int y);
	void formigaSetEner(int id, int e);

	int formigaPosX(int id);
	int formigaPosY(int id);
	int formigaEnerg(int id);

	int numFormigas();
	void acrescentaFormiga(int x, int y);
	void mataFormiga(int id);

	int formigaMov(int id);
	int formigaVisao(int id);

	Ninho(int x, int y, int energia);
	~Ninho();
};

