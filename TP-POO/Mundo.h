#pragma once
#include "librarias.h"

class Ninho;
class Interface;

class Mundo{

	vector<Ninho> ninhos;

	int dimensao;
	int energNinhos;
	int perFazNovoNinho;
	int transFormNin;
	int numPosMigalhas;
	int energiaInicialMig;
	int migalhaSorteio;

public:

	int getDim() const;
	void setDim(int dim);
	void imprime();
	void acrescentaNinho(int x, int y, int *cx,int *cy);
	void trataFormiga(int qnts, int id);
	
	bool ocupaPos(int x, int y);
	int numNinhos();

	string listaPos(int x, int y);
	string listaNinho(int id);
	string getAsString() const;

	void iteracao(int temp);
	void regraPasseia(int id, int idn);
	void energiaIteracao(int movEX, int movEY, int idn, int idf);

	
	Mundo(int dim, int energNinhos, int perFazNovoNinho, int transFormNin, int numPosMigalhas, int energiaInicialMig, int migalhaSorteio);
	~Mundo();
};

