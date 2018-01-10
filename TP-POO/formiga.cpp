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
		//Regra * rVPN = new RegraVaiParaNinho;
		Regra * rP = new RegraPasseia;
		regras.push_back(rP);
	}

	/*if (getDenom() == 'A') {
		Regra * rA = new RegraAssalta;
		Regra * rPe = new RegraPersegue;
		Regra * rCM = new RegraComeMigalha;
		Regra * rPM = new RegraProcuraMigalha;
		Regra * rP = new RegraPasseia;
	}

	

	if (getDenom() == 'V') {
		Regra * rPr = new RegraProtege;
		Regra * rCM = new RegraComeMigalha;
		Regra * rPM = new RegraProcuraMigalha;
		Regra * rP = new RegraPasseia;
	}*/

		/*/
		C - RegraFoge														RegraComeMigalha	RegraProcuraMigalha		RegraVaiParaNinho	RegraPasseia
		V -					RegraProtege									RegraComeMigalha	RegraProcuraMigalha							RegraPasseia
		A -									RegraAssalta	RegraPersegue	RegraComeMigalha	RegraProcuraMigalha							RegraPasseia
		E -																	RegraComeMigalha												RegraPasseia
		/*/
}

void Formiga::cumpreRegras(int dim, vector <Elementos*> elem, int x, int y, int idF) {
	
	int iniX = x;
	int iniY = y;

	int *xi = &x;
	int *yi = &y;

	int teste = 1;

	for (unsigned int i = 0; i < regras.size(); i++) {
			
		if (regras[i]->condicao(&x, &y, dim, elem, getVisao())){
			
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

	int energGasta = abs(movEX) + abs(movEY) + 1;
	int energInicial = getEner();
	int energAtual = energInicial - energGasta;

	setEner(energAtual);
}
