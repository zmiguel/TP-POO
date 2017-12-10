#pragma once
#include "librarias.h"

class Ninho;
class Interface;

class Mundo{

	//Mundo composi��o perante os ninhos
	//Ninhos s�o de agrega��o perante as formigas
	vector<Ninho> ninhos;

	int dimensao;
	int numNinhos;
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
	void criaNinhos();
	string getAsString(int *x, int *y) const;
	Mundo(int dim, int numNinhos, int perFazNovoNinho, int transFormNin, int numPosMigalhas, int energiaInicialMig, int migalhaSorteio);
	~Mundo();
};

