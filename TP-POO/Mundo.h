#pragma once
#include "librarias.h"

class Ninho;
class Interface;

class Mundo{

	//Mundo composição perante os ninhos
	//Ninhos são de agregação perante as formigas
	vector<Ninho> ninhos;

	int dimensao;
	int energNinhos; // colocar const
	int perFazNovoNinho;
	int transFormNin;
	int numPosMigalhas;
	int energiaInicialMig;
	int migalhaSorteio;

public:

	int getDim() const;
	void setDim(int dim);
	void imprime();
	void acrescentaNinho(int x, int y);
	void formiga(int qnts, int id);
	int numNinhos();
	string listaNinho(int id);
	string getAsString(int *x, int *y) const;
	int formigaPosX(int id);
	int formigaPosY(int id);
	Mundo(int dim, int energNinhos, int perFazNovoNinho, int transFormNin, int numPosMigalhas, int energiaInicialMig, int migalhaSorteio);
	~Mundo();
};

