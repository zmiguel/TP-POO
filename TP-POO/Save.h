#pragma once
#include "librarias.h"

class Save
{
	vector<Elementos*> elem;
	string nome;

public:

	string getNome();
	void setNome(string nome);

	vector<Elementos*> getElementos();
	void setElementos(vector<Elementos*> elem);

	Save(string nome, vector<Elementos*> elem);

	~Save();
};

