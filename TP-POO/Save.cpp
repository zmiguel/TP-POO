#include "Save.h"



string Save::getNome()
{
	return nome;
}

void Save::setNome(string n)
{
	nome = n;
}

vector<Elementos*> Save::getElementos()
{
	return elem;
}

void Save::setElementos(vector<Elementos*> elemento)
{
	for (Elementos *i : elemento) {
		elem.push_back(i);
	}
}

Save::Save(string nome, vector<Elementos*> elem)
{
	setNome(nome);
	setElementos(elem);
}


Save::~Save()
{
}
