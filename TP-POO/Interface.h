#pragma once
#include "librarias.h"

class Mundo;

class Interface{
	Mundo * mundo;

public:
	Interface(Mundo * m);
	void corre();
	~Interface();
};

