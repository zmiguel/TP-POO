#pragma once
#include "librarias.h"

class Elementos;
class Regra;

class Formiga {

	int id;
	static int i;
	int posX;
	int posY;
	char denom;
	int energiaInicial;
	int mov;
	int visao;
	int energia;
	int idNinho;

	vector<Regra*> regras;

public:
	Formiga(int x, int y, char c);
	
	int getX()const;
	int  getY()const;
	int getEner();
	int getID();
	char getDenom();

	void setEner(int e);
	void setIdNinho(int i);
	int getIdNinho();
	void setX(int x);
	void setY(int y);
	void setEnerInicial(int e);
	void setVisao(int v);
	void setMov(int m);

	int getMov();
	int getVisao();
	
	string getAsString();
	bool ocupaPos(int x, int y, vector <Elementos*> elem);
	void preencheRegras();
	void regrasPercorre(int dim, vector<Elementos*> elem, int x, int y, int idF);
	void energiaIteracao(int movEX, int movEY);
};


class Exploradora : public Formiga {
	
	public:

		Exploradora(int posX, int posY, char denom):Formiga(posX,posY,denom) {
			
		}



};



