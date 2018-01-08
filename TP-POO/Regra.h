#pragma once
#include "librarias.h"

class Elementos;

class Regra
{
	bool regra;

	//virtual bool --> Condição
	//virtual void --> Ação

public:
	~Regra();

	Regra(bool rule);

	bool getRegras(int i, int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis);

	bool regraPasseia(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis);

	bool ocupaPos(int x, int y, vector<Elementos*> elem);

		bool regraFoge();
		bool regraProtege();
		bool regraAssalta();
		bool regraPersegue();
		bool regraComeMigalha();
		bool regraProcuraMigalha();
		bool regraVaiParaNinho();

};