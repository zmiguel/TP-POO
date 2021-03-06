#include "Formiga.h"

int Formiga::i = 1;

Formiga::Formiga(int x, int y, char c):posX(x), posY(y){
	this->id = i++;
	this->denom = c;
	this->itNinho = 0;
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
	energiaInicial = e;
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

int Formiga::getEnergiaInicial() {
	return energiaInicial;
}

void Formiga::setIt(int it)
{
	itNinho = it;
}

int Formiga::getIt()
{
	return itNinho;
}


//---------POSI��ES-----------//

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


//----.-----DESCRI��O---------//

string Formiga::getAsString() {
	
	ostringstream oss;

	oss << "\nFormiga " << denom 
		<< " ID: " << id
		<< " Energia: " << energia
		<< " (" << posX << ","
		<< posY << ")" << " I: " << itNinho;

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

void Formiga::acrescentaRegras() {
	
	bool flag = false;
	int i = 1;

	if (getDenom() == 'E') {
		Regra * rCM = new RegraComeMigalha;
		regras.push_back(rCM);
		Regra * rP = new RegraPasseia;
		regras.push_back(rP);
	}

	if (getDenom() == 'C') {
		Regra * rF = new RegraFoge;
		regras.push_back(rF);
		Regra * rCM = new RegraComeMigalha;
		regras.push_back(rCM);
		Regra * rPM = new RegraProcuraMigalha;
		regras.push_back(rPM);
		Regra * rVPN = new RegraVaiParaNinho;
		regras.push_back(rVPN);
		Regra * rP = new RegraPasseia;
		regras.push_back(rP);
	}

	if (getDenom() == 'V') {
		Regra * rPr = new RegraProtege;
		regras.push_back(rPr);
		Regra * rCM = new RegraComeMigalha;
		regras.push_back(rCM);
		Regra * rPM = new RegraProcuraMigalha;
		regras.push_back(rPM);
		Regra * rP = new RegraPasseia;
		regras.push_back(rP);
	}

	if (getDenom() == 'A') {
		Regra * rA = new RegraAssalta;
		regras.push_back(rA);
		Regra * rPe = new RegraPersegue;
		regras.push_back(rPe);
		Regra * rCM = new RegraComeMigalha;
		regras.push_back(rCM);
		Regra * rPM = new RegraProcuraMigalha;
		regras.push_back(rPM);
		Regra * rP = new RegraPasseia;
		regras.push_back(rP);
	}

	if (getDenom() == 'H') {
		Regra *rC = new RegraCura;
		regras.push_back(rC);
		Regra * rCM = new RegraComeMigalha;
		regras.push_back(rCM);
		Regra * rPM = new RegraProcuraMigalha;
		regras.push_back(rPM);
		Regra * rP = new RegraPasseia;
		regras.push_back(rP);
	}

		/*
		C -					RegraFoge														RegraComeMigalha	RegraProcuraMigalha		RegraVaiParaNinho	RegraPasseia
		V -									RegraProtege									RegraComeMigalha	RegraProcuraMigalha							RegraPasseia
		A -													RegraAssalta	RegraPersegue	RegraComeMigalha	RegraProcuraMigalha							RegraPasseia
		E -																					RegraComeMigalha												RegraPasseia
		H - RegraCura																		RegraComeMigalha	RegraProcuraMigalha							RegraPasseia
		*/
}

void Formiga::cumpreRegras(int dim, vector <Elementos*> elem, int x, int y, int idF) {
	
	int iniX = x;
	int iniY = y;

	int *xi = &x;
	int *yi = &y;

	int teste = 1;

	for (unsigned int i = 0; i < regras.size(); i++) {
		
		if (regras[i]->condicao(&x, &y, dim, elem, getVisao())) {

			regras[i]->acao(&x, &y, dim, elem, getMov(), getVisao());

			int xOcup = *xi;
			int yOcup = *yi;

			setX(xOcup);
			setY(yOcup);

			int movEX = iniX - xOcup;
			int movEY = iniY - yOcup;

			energiaIteracao(movEX, movEY);
			break;
		}
	}
		
}

void Formiga::energiaIteracao(int movEX, int movEY) {

	int energGasta = 1;

	if (getDenom() == 'A') {
		energGasta = 1 + 2*( abs(movEX) + abs(movEY));
	}
	else {
		energGasta = 1 + abs(movEX) + abs(movEY);
	}

	int energInicial = getEner();
	int energAtual = energInicial - energGasta;

	setEner(energAtual);
}
