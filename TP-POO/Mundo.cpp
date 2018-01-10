#include "Mundo.h"

Mundo::Mundo(int dim, int energNinhos, int perFazNovoNinho, int transFormNin, int percentagemPosMigalhas, int energiaInicialMig, int migalhaSorteio){

	this->dimensao = dim;
	this->energNinhos = energNinhos;
	this->perFazNovoNinho = perFazNovoNinho;
	this->transFormNin = transFormNin;
	this->percentagemPosMig = percentagemPosMigalhas;
	this->energiaInicialMig = energiaInicialMig;
	this->migalhaSorteio = migalhaSorteio;
}

//------------GET'S & SET'S----------------//

int Mundo::getDim() const{
	return dimensao;
}

void Mundo::setDim(int dim) {
	dimensao = dim;
}

vector<Elementos*> Mundo::getMundo() {

	vector <Elementos*> aux;

	for (unsigned int i = 0; i != elementos.size(); i++) {
		aux.push_back(elementos[i]);
	}

	return aux;
}


//---------------LISTAGENS------------------//

string Mundo::getAsString() const {

	ostringstream oss;

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		oss << ninhos[i]->getAsString();
	}

	return oss.str();
}

string Mundo::listaNinho(int id) {

	ostringstream oss;

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		if (id == ninhos[i]->getID()) {
			oss << ninhos[i]->getAsString();
		}
	}

	return oss.str();
}

string Mundo::listaPos(int x, int y) {

	ostringstream oss;

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		if (ninhos[i]->getX() == x && ninhos[i]->getY() == y) {
			oss << ninhos[i]->ninhoInfo();
		}
	}

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		for (int k = 0; k < ninhos[i]->numFormigas(); k++) {
			if (ninhos[i]->formigaPosX(k) == x && ninhos[i]->formigaPosY(k) == y) {
				oss << ninhos[i]->formigaInfo(k);
			}
		}
	}

	for (unsigned int i = 0; i < migalhas.size(); i++) {
		if (migalhas[i]->getPosX() == x && migalhas[i]->getPosY() == y) {
			oss << migalhas[i]->getAsString();
		}
	}


	return oss.str();
}


//--------------MIGALHAS--------------//

void Mundo::acrescentaUmaMigalha(int x, int y) {

	if (x < getDim() && y < getDim() && ocupaPos(x, y) == false) {

		Migalha* ob = new Migalha(x, y, energiaInicialMig);
		migalhas.push_back(ob);

		elementosAtualiza();
	}
	else {
		cout << "Posicao ja ocupada para acrescentar uma migalha"<< endl;
	}
}

void Mundo::acrescentaMigalhas() {

	int numPosOcup = dimensao * dimensao * percentagemPosMig / 100;

	while (numPosOcup > 0) {
		
		int x = rand() % getDim();
		int y = rand() % getDim();

		if (x < getDim() && y < getDim() && ocupaPos(x,y) == false) {

			Migalha* ob = new Migalha(x, y, energiaInicialMig);
			migalhas.push_back(ob);

			elementosAtualiza();

			numPosOcup--;
		}
	}
}

void Mundo::migalhasPerdeIteracao() {

	int energiaDecrementa = 1;

	for (unsigned int i = 0; i < migalhas.size(); i++) {
		migalhas[i]->setEnergia(migalhas[i]->getEnergia() - 1);
	}

	for (unsigned int i = 0; i < migalhas.size(); i++) {

		if (migalhas[i]->getEnergia() < energiaInicialMig * 0.1) {
			delete migalhas[i];
			migalhas.erase(migalhas.begin() + i);
			i = 0;
		}

	}

	if (migalhas.size() == 1 && migalhas[0]->getEnergia() < energiaInicialMig * 0.1) {
		delete migalhas[0];
		migalhas.erase(migalhas.begin());
	}

	//melhorar

}

void Mundo::sorteiaMigalha() {
	
	int sorteio = rand() % migalhaSorteio;

	while (sorteio > 0) {

		int x = rand() % getDim();
		int y = rand() % getDim();

		if (x < getDim() && y < getDim() && ocupaPos(x, y) == false) {

			Migalha* ob = new Migalha(x, y, energiaInicialMig);
			migalhas.push_back(ob);

			elementosAtualiza();

			sorteio--;
		}
	}
}


//---------------NINHOS-----------------//

bool Mundo::existeNinhoID(int id) {
	for (Ninho *n : ninhos) {
		if (n->getID() == id) {
			return true;
		}
	}
	return false;
}

int Mundo::numNinhos() {
	return (int) ninhos.size();
}

bool Mundo::confirmaNinho(int id) {

	for (Ninho* i : ninhos) {
		if (i->getID() == id) {
			return true;
		}
	}

	return false;
}

void Mundo::acrescentaNinho(int x, int y){
	
	if (ocupaPos(x, y) == false) {
		Ninho* ob = new Ninho(x, y, energNinhos);
		ninhos.push_back(ob);


		for (unsigned i = 0; i < ninhos.size(); i++) {
			ninhos[i]->setPosVetor(i);
		}

		elementosAtualiza();
	}
	else {
		cout << "\n\n\n Foi tentado ser criado um ninho numa posição já ocupada!";
	}
}

void Mundo::inseticida(int id) {

	for (unsigned n = 0; n < ninhos.size(); n++) {
		if (ninhos[n]->getID() == id) {
			delete ninhos[n];
			ninhos.erase(ninhos.begin() + n);
		}
	}

	for (unsigned i = 0; i < ninhos.size(); i++) {
		ninhos[i]->setPosVetor(i);
	}
	
	elementosAtualiza();
}  

void Mundo::acrescentaEnergiaNinho(int idN, int energia) {

	int pos;

	for (unsigned n = 0; n < ninhos.size(); n++) {
		if (ninhos[n]->getID() == idN) {
			pos = n;
		}
	}

	int power = ninhos[pos]->getEnergia() + energia;
	ninhos[pos]->setEnergia(power);
}

//---------------FORMIGAS---------------//

void Mundo::trataFormiga(int qnts, int id, char c) {

	int dim = getDim();
	int x = rand() % dim;
	int y = rand() % dim;
	int pos;

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		if (ninhos[i]->getID() == id) {
			pos = ninhos[i]->getPosVetor();
			break;
		}
	}


	while (qnts != 0) {

		while (ocupaPos(x, y) == true) {
			x = rand() % dim;
			y = rand() % dim;
		}

		if (c == 'C') {
			ninhos[pos]->acrescentaFormiga(x, y, c, id);
		}

		if(c == 'E'){
			ninhos[pos]->acrescentaFormiga(x, y, c, id);
		}

		if (c == 'V') {
			ninhos[pos]->acrescentaFormiga(x, y, c, id);
		}

		if (c == 'A') {
			ninhos[pos]->acrescentaFormiga(x, y, c, id);
		}

		qnts--;

		
		elementosAtualiza();
	};
}

void Mundo::assassinaFormiga(int x, int y) {
	
	for (unsigned int i = 0; i < elementos.size(); i++) {
		if (elementos[i]->getPosX() == x && elementos[i]->getPosY() == y && elementos[i]->getDenom() != 'N' && elementos[i]->getDenom() != 'M') {
			
			for (unsigned n = 0; n < ninhos.size(); n++) {
					ninhos[n]->assassinaProcura(elementos[i]->getPosX(), elementos[i]->getPosY());
			}
		}
	}
	elementosAtualiza();
}

void Mundo::acrescentaFormiga(char denom, int idN, int x, int y) {

	int pos;

	for (unsigned n = 0; n < ninhos.size(); n++) {
		if (ninhos[n]->getID() == idN) {
			pos = n;
			break;
		}
	}
	
	cout << denom<< endl;
	cout << idN << endl;
	cout << x << endl;
	cout << y << endl;


	if (ocupaPos(x, y) == false) {
		ninhos[pos]->acrescentaFormiga(x, y, denom, idN);
	}

	elementosAtualiza();

}

void Mundo::acrescentaEnergiaFormiga(int x, int y, int energia) {

	int power;

	for (unsigned int i = 0; i < ninhos.size(); i++){
		for (int j = 0; j < ninhos[i]->numFormigas(); j++) {
			if (ninhos[i]->formigaPosX(j) == x && ninhos[i]->formigaPosY(j) == y) {
				power = ninhos[i]->formigaEnerg(j) + energia;
				ninhos[i]->formigaSetEner(j, power);
				break;
			}
		}
	}
}

//---------------ELEMENTOS---------------//

void Mundo::elementosAtualiza() {

	for (vector< Elementos*>::iterator it = elementos.begin(); it != elementos.end(); ++it) {
		delete (*it);
	}

	elementos.clear();

	for (unsigned int i = 0; i < ninhos.size(); i++) {
		Elementos * obj = new Elementos(ninhos[i]->getX(), ninhos[i]->getY(), ninhos[i]->getDenom(), ninhos[i]->getID(), ninhos[i]->getEnergia(), ninhos[i]->getEnergia(), 0);
		elementos.push_back(obj);
		for (int k = 0; k < ninhos[i]->numFormigas(); k++) {
			Elementos * obj = new Elementos(ninhos[i]->formigaPosX(k), ninhos[i]->formigaPosY(k), ninhos[i]->getFormigaDenom(k), ninhos[i]->getID(), ninhos[i]->formigaEnerg(k), ninhos[i]->formigaEnergiaInicial(k), ninhos[i]->formigaGetIt(k));
			elementos.push_back(obj);
		}
	}

	for (unsigned int m = 0; m < migalhas.size(); m++) {
		Elementos * obj = new Elementos(migalhas[m]->getPosX(), migalhas[m]->getPosY(), 'M', migalhas[m]->getId(), migalhas[m]->getEnergia(), migalhas[m]->getEnergia(), 0);
		elementos.push_back(obj);
	}
}

bool Mundo::ocupaPos(int x, int y) {

	for (unsigned int i = 0; i < elementos.size(); i++) {
		if (elementos[i]->getPosX() == x && elementos[i]->getPosY() == y) {
			return true;
		}
	}
	return false;
}

char Mundo::ocupaPosChar(int x, int y) {

	for (unsigned int i = 0; i < elementos.size(); i++) {
		if (elementos[i]->getPosX() == x && elementos[i]->getPosY() == y) {
			return elementos[i]->getDenom();
		}
	}
	return '0';
}


//---------------ITERAÇÃO---------------//

void Mundo::iteracao(int temp){

	for (int it = 0; it < temp; it++) {
		for (unsigned n = 0; n < ninhos.size(); n++) {
			for (int f = 0; f < ninhos[n]->numFormigas(); f++) {
				ninhos[n]->regras(f, getDim(), elementos);
				setEnergias();
				elementosAtualiza();
			}
		}

		iteracaoAtualiza();
		migalhasPerdeIteracao();
		sorteiaMigalha();
		elementosAtualiza();
	}
}

void Mundo::iteracaoAtualiza() {
	for (Ninho * n : ninhos) {
		n->setIteracaoFormiga();
	}
}

void Mundo::setEnergias() {

	for (Elementos *i : elementos) {
		
		if (i->getDenom() == 'M') {
			for (Migalha *m : migalhas) {
				if (i->getPosX() == m->getPosX() && i->getPosY() == m->getPosY()) {
					m->setEnergia(i->getEnergia());
				}
			}
		}

		if (i->getDenom() == 'M') {
			for (Ninho *n : ninhos) {
				if (i->getPosX() == n->getX() && i->getPosY() == n->getY()) {
					n->setEnergia(i->getEnergia());
				}
			}
		}
		
		if (i->getDenom() != 'M'  && i->getDenom() != 'N') {
			for (Ninho *n : ninhos) {
				for (int k = 0; k < n->numFormigas(); k++) {
					if (n->formigaPosX(k) == i->getPosX() && n->formigaPosY(k) == i->getPosY()) {
						n->formigaSetEner(k, i->getEnergia());
					}
				}
			}
		}
	}
}


Mundo::~Mundo()
{
}
