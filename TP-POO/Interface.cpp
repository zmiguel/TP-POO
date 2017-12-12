#include "Interface.h"
#include "Mundo.h"

Interface::Interface(Mundo * m){
	mundo = m;
}

void Interface::corre() {

	mundo->imprime();
	
	string comando;
	bool flag = true;
	char nextChar;
	int comandoEsp = 0;
	string str;
	int num;
	int num2;
	int num3;
	char c;

	int x = 0;
	int y = 0;


	while (flag == true) {

		comandoEsp = 0;
		Consola::gotoxy(x, y);
		cout << "\n> ";
		getline(cin, comando);
		istringstream iss(comando);

		for (int i = 0; i < int(comando.length()); i++) {
			nextChar = comando.at(i);
			if (isspace(comando[i])) {
				comandoEsp++;
			}
		}

		if (comandoEsp == 0) {
			iss >> str;
			if (str.compare("tempo") == 0) {
				cout << "\n> Passou uma iteracao" << endl;
			}
			else {
				if (str.compare("listamundo") == 0) {
					cout << mundo->getAsString(&x, &y);
				}
				else {
					if (str.compare("sair") == 0) {
						flag = false;
					}
				}
			}
		}
		else {
			if (comandoEsp == 1) {
				iss >> str;
				iss >> num;
				if (iss.fail()) {
					cout << num; // ver isto
				}
				else {
					if (str.compare("tempo") == 0 && num > 0) {
						cout << "\n> Passaram " << num << " iteracoes" << endl;
					}
					else {
						if (str.compare("listaninho") == 0 && num <= mundo->numNinhos())
							cout << mundo->listaNinho(num);
					}
				}
			}
			else {
				if (comandoEsp == 2) {
					iss >> str;
					iss >> num;
					iss >> num2;
					if (iss.fail()) {
					
					}
					else {
						if (str.compare("ninho") == 0 && num < mundo->getDim() && num2 < mundo->getDim()) {
							// introduzir condição de que um ninho introduzido não pode ter as mesmas coordenadas que outro
							mundo -> acrescentaNinho(num, num2, &x, &y);
							mundo->imprime();
						}
					}
				}
				else {
					if (comandoEsp == 3) {
						iss >> str;
						iss >> num;
						if (!iss.fail()) {
							iss >> c;
							if (!iss.fail()) {
								iss >> num3;
								if (!iss.fail()) {
									if (str.compare("criaf") == 0 && num > 0 && c == 'E' && num3 <= mundo->numNinhos()) {
										mundo->trataFormiga(num, num3);
										mundo->imprime();
									}
									else {
										printf("Erro de sintaxe");
									}
								
								}
							
							}
						}
					
					}
				
				}
			}
		}
		iss.str("");
		
	}
}



Interface::~Interface()
{


}
