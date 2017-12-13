#include "librarias.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

	bool flag = false;
	int valor;

	srand(time(NULL));


	while (flag == false) {

		Consola::setTextColor(Consola::VERDE);
		Consola::gotoxy(35, 1);
		Consola::setTextSize(18, 18);
		cout << "TRABALHO PRÁTICO - PROGRAMAÇÃO ORIENTADA A OBJECTOS";
		Consola::gotoxy(47, 3);
		cout << "1 - NOVO JOGO";
		Consola::gotoxy(47, 4);
		cout << "2 - CARREGAR JOGO";
		Consola::gotoxy(47, 5);
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

		system("cls");
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