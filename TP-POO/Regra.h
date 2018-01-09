#pragma once
#include "librarias.h"

class Elementos;
class Mundo;

class Regra{

	protected:

	public:
		~Regra();
		Regra();
	
		virtual bool condicao(int *x, int *y, int dim, vector <Elementos*> elem) = 0;
		virtual void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis) = 0;

		bool ocupaPos(int x, int y, vector<Elementos*> elem);

};


class RegraPasseia :public Regra {

	public:
		RegraPasseia() :Regra() {}

			bool condicao(int *x, int *y, int dim, vector <Elementos*> elem) {
				return true;
			}
	
			void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis) {
		
				bool flag = false;

				int xi = *x; 
				int yi = *y;; 

				while (flag == false) {

					*x = xi + (rand() % (mov + 10) + (-mov));															
					*y = yi + (rand() % (mov + 10) + (-mov));															
					if (*x >= 0 && *x < dim && *y >= 0 && *y < dim && ocupaPos(*x, *y, elem) == false) {				
						flag = true;
					}
					else {
						*x = xi;
						*y = yi;
					}
				}
			}
};

class RegraFoge : public Regra {
	
	public:
		RegraFoge() :Regra() {}

		bool condicao() {
			return true;
			
		}
		void acao() {}

			
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

	bool condicao(int *x, int *y, int dim, vector <Elementos*> elem) {
		
		for (unsigned int i = 0; i < elem.size(); i++) {
			
			if (elem[i]->getDenom() == 'M' && (elem[i]->getPosX() == *x - 1 && elem[i]->getPosY() == *y)) {
				return true;
			}

			if (elem[i]->getDenom() == 'M' && (elem[i]->getPosX() == *x + 1 && elem[i]->getPosY() == *y)) {
				return true;
			}

			if (elem[i]->getDenom() == 'M' && (elem[i]->getPosX() == *x && elem[i]->getPosY() == *y - 1)) {
				return true;
			}

			if (elem[i]->getDenom() == 'M' && (elem[i]->getPosX() == *x && elem[i]->getPosY() == *y + 1)) {
				return true;
			}
		
		}
		
		return false;
	}


	void acao(int *x, int *y, int dim, vector <Elementos*> elem, int mov, int vis) {

		cout << "Come!\n";
	};
};

class RegraProcuraMigalha : public Regra {
	
public:
	RegraProcuraMigalha() :Regra() {}

	bool condicao() {}
	void acao() {

		cout << "algo";
	};
};

class RegraVaiParaNinho : public Regra {
	
public:
	RegraVaiParaNinho() :Regra() {}

	bool condicao() {}
	void acao() {

		cout << "algo";
	};
};