#include "librarias.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

	bool flag = false;
	int valor;

	srand(time(NULL));
	Consola::setScreenSize(128, 32);
	Consola::setTextColor(Consola::VERDE);


	while (flag == false) {
		Consola::gotoxy(39, 1);
		Consola::setTextSize(18, 18);
		cout << "TRABALHO PRÁTICO - PROGRAMAÇÃO ORIENTADA A OBJECTOS";
		Consola::gotoxy(50, 3);
		cout << "1 - NOVO JOGO";
		Consola::gotoxy(50, 4);
		cout << "2 - CARREGAR JOGO";
		Consola::gotoxy(50, 5);
		cout << "3 - SAIR";

		Consola::gotoxy(45, 7);
		cout << "> ";
		string s;
		cin >> s;
		istringstream iss(s);

		if (iss >> valor) {
			if (valor > 0 && valor < 4) {
				flag = true;
			}
		}

		Consola::clrscr();
	}


	switch (valor) {
	
	case 1: Configs c;
			c.config();
			break;
	case 2: cout << "Not yet";
	case 3: exit(0);
	}






	

	system("pause");
}