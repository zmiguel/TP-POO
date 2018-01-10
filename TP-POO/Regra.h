#pragma once
#include "librarias.h"

class Elementos;
class Mundo;

class Regra{

	public:
		~Regra();
		Regra();
	
		virtual bool condicao(int *x, int *y, int dim, vector <Elementos*> elem, int vis) = 0;
		virtual void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis) = 0;

		bool ocupaPos(int x, int y, vector<Elementos*> elem);

		bool estaVisao(int x, int y, int vis, int xp, int yp);

		bool estaMov(int x, int y, int mov, int xp, int yp);

};


class RegraPasseia :public Regra {

	public:
		RegraPasseia() :Regra() {}

		bool condicao(int *x, int *y, int dim, vector <Elementos*> elem, int vis);

		void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis);
};

class RegraFoge : public Regra {
	
	public:
		RegraFoge() :Regra() {}

		bool condicao(int *x, int *y, int dim, vector <Elementos*> elem, int vis);

		void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis);		
};

class RegraProtege : public Regra {

public:
	RegraProtege() :Regra() {}

	bool condicao() {}
	void acao() {

		cout << "algo";
	};
};

class RegraAssalta : public Regra {

public:
	RegraAssalta() :Regra() {}

	bool condicao() {}
	void acao() {

		cout << "algo";
	};
};

class RegraPersegue : public Regra {

public:
	RegraPersegue() :Regra() {}

	bool condicao() {}
	void acao() {

		cout << "algo";
	};
};

class RegraComeMigalha : public Regra {
	
public:
	RegraComeMigalha() :Regra() {}

	bool condicao(int *x, int *y, int dim, vector <Elementos*> elem, int vis);

	void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis);

};

class RegraProcuraMigalha : public Regra {
	
public:
	RegraProcuraMigalha() :Regra() {}

	bool condicao() {}
	void acao() {

		cout << "algo";
	};
	bool condicao(int * x, int * y, int dim, vector<Elementos*> elem, int vis);
	void acao(int * x, int * y, int dim, vector<Elementos*> elem, int mov, int vis);
};

class RegraVaiParaNinho : public Regra {
	
public:
	RegraVaiParaNinho() :Regra() {}

	bool condicao(int *x, int *y, int dim, vector <Elementos*> elem, int vis);

	void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis);
};