#pragma once
#include "librarias.h"

class Formiga;
class Exploradora;

class Ninho{
	int id;
	static int i;
	int energiaInicial;
	int energia;
	int perFazNovoNinho;
	int transFormNin;
	int PosX;
	int PosY;


	int posVetor;
	char denom = 'N';

	vector<Formiga*> formigas;
public:
	string getAsString()const;
	string formigaInfo(int id);
	void formigaSetIdNinho(int n);
	void setPosVetor(int pos);
	int getEnergia();
	void setEnergia(int e);
	int getPosVetor();
	string ninhoInfo() const;

	void setID(int id);

	int getX()const;
	int getY()const;
	int getID()const;

	int getFormigaDenom(int id);

	void formigaSetX(int id, int x);
	void formigaSetY(int id, int y);
	void formigaSetEner(int id, int e);

	int getIDNinho(int idF);

	int suaFormigaPos(int x, int y);

	int formigaPosX(int id);
	int formigaPosY(int id);
	int formigaEnerg(int id);

	int numFormigas();
	char getDenom();
	void mataFormiga(int id);

	void assassinaProcura(int x, int y);

	void acrescentaFormiga(int x, int y, char c, int idN);

	void regras(int idN, int dim, vector<Elementos*> elem);

	int formigaMov(int id);
	int formigaVisao(int id);

	Ninho(int x, int y, int energia);
	~Ninho();
};

