#pragma once
#include "librarias.h"

class Ninho;
class Migalha;
class Interface;
class Elementos;

class Mundo{

	vector<Ninho*> ninhos;
	vector<Migalha*> migalhas;
	vector<Elementos*> elementos;

	int dimensao;
	int energNinhos;
	int perFazNovaFormiga;
	int transFormNin;
	int percentagemPosMig;
	int energiaInicialMig;
	int migalhaSorteio;

public:

	int getDim() const;
	void acrescentaUmaMigalha(int x, int y);
	void acrescentaMigalhas();
	bool existeNinhoID(int id);
	int numNinhos();

	bool confirmaNinho(int id);

	void acrescentaNinho(int x, int y);

	void setDim(int dim);
	
	bool ocupaPos(int x, int y);

	bool ocupaPos2(int x, int y);

	char ocupaPosChar(int x, int y);
	
	void migalhasPerdeIteracao();

	void sorteiaMigalha();

	void setEnergias();

	void trataFormiga(int qnts, int id, char c);

	void assassinaFormiga(int x, int y);
	void acrescentaFormiga(char denom, int idN, int x, int y);
	void acrescentaEnergiaFormiga(int x, int y, int energia);
	void inseticida(int id);

	void acrescentaEnergiaNinho(int idN, int energia);

	string listaPos(int x, int y);
	string listaNinho(int id);
	string getAsString() const;

	void iteracao(int temp);

	void iteracaoAtualiza();

	void elementosAtualiza();

	
	Mundo(int dim, int energNinhos, int perFazNovoNinho, int transFormNin, int numPosMigalhas, int energiaInicialMig, int migalhaSorteio);
	~Mundo();
	vector<Elementos*> getMundo();
	void setTransferencia(int t);
};

