#pragma once
#include "librarias.h"

class Mundo;
class Save;

class Interface{
	Mundo * mundo;
	vector<Save*> saves;

public:
	Interface(Mundo * m);
	void deleteDefault();
	void deleteNome(string nome);
	void corre();
	void imprime();
	~Interface();
};

