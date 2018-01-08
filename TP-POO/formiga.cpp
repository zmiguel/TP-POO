#include "Formiga.h"

int Formiga::i = 1;

Formiga::Formiga(int x, int y, char c):posX(x), posY(y){
	this->id = i++;
	this->denom = c;
}

//--------CARACTERISTICAS-------//

int Formiga::getID() {
	return id;
}

int Formiga::getEner() {
	return energia;
}

char Formiga::getDenom() {

	return denom;
}

void Formiga::setEnerInicial(int e)
{
	energia = e;
}

void Formiga::setEner(int e) {
	energia = e;
}

void Formiga::setIdNinho(int i) {
	idNinho = i;
}

int Formiga::getIdNinho() {
	return idNinho;
}


//---------POSIÇÕES-----------//

void Formiga::setX(int x) {
	posX = x;
}

void Formiga::setY(int y) {
	posY = y;
}

int Formiga::getX() const {
	return posX;
}

int Formiga::getY() const {
	return posY;
}


//----.-----DESCRIÇÃO---------//

string Formiga::getAsString() {
	
	ostringstream oss;

	oss << "\nFormiga ID: " << id
		<< " Energia: " << energia
		<< " (" << posX << ","
		<< posY << ")";

	return oss.str();
}


//-----------REGRAS----------//

int Formiga::getMov()
{
	return mov;
}

int Formiga::getVisao()
{
	return visao;
}

void Formiga::setVisao(int v)
{
	visao = v;
}

void Formiga::setMov(int m)
{
	mov = m;
}

bool Formiga::ocupaPos(int x, int y, vector<Elementos*> elem) {

	for (unsigned int i = 0; i < elem.size(); i++) {
		if (elem[i]->getPosX() == x && elem[i]->getPosY() == y) {
			return true;
		}
	}

	return false;
}

void Formiga::preencheRegras() {
	
	if (getDenom() == 'E') {
		Regra* ob = new Regra(false); //REGRA FOGE
		regras.push_back(ob);
		Regra* ob1 = new Regra(false); //REGRA PROTEGE
		regras.push_back(ob1);
		Regra* ob2 = new Regra(false); //REGRA ASSALTA
		regras.push_back(ob2);
		Regra* ob3 = new Regra(false); //REGRA PERSEGUE
		regras.push_back(ob3);
		Regra* ob4 = new Regra(true); //REGRA COME MIGALHA
		regras.push_back(ob4);
		Regra* ob5 = new Regra(false); //REGRA PROCURA MIGALHA
		regras.push_back(ob5);
		Regra* ob6 = new Regra(false); //REGRA VAI PARA NINHO
		regras.push_back(ob6);
		Regra* ob7 = new Regra(true); //REGRA PASSEIA
		regras.push_back(ob7);
	}
}

void Formiga::regrasPercorre(int dim, vector <Elementos*> elem, int x, int y, int idF) {
	
	bool flag = false;
	bool flag1 = false;
	int iniX = x;
	int iniY = y;

	int *xi = &x;
	int *yi = &y;

	for (unsigned int i = 0; i < regras.size(); i++) {
		flag = regras[i]->getRegras(i, xi, yi, dim, elem, getMov(), getVisao());
		int xOcup = *xi;
		int yOcup = *yi;

		if (flag == true) {
				
			setX(xOcup);
			setY(yOcup);

			int movEX = iniX - xOcup;
			int movEY = iniY - yOcup;

			energiaIteracao(movEX, movEY);
		}
	}
}

void Formiga::energiaIteracao(int movEX, int movEY) {

	int energGasta = abs(movEX) + abs(movEY) + 1;
	int energInicial = getEner();
	int energAtual = energInicial - energGasta;

	setEner(energAtual);
}
