#include "Interface.h"
#include "Mundo.h"

Interface::Interface(Mundo * m){
	mundo = m;
}

void Interface::corre() {

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


	while (true) {
	  mundo->imprime();
	  Consola::gotoxy(0, 1);
	  cout << "                    ";

		comandoEsp = 0;
		Consola::gotoxy(0, 0);
		cout << "para ver todos os comandos escreva [help]\n> ";
		getline(cin, comando);
		istringstream iss(comando);

		for (int i = 0; i < int(comando.length()); i++) {
			nextChar = comando.at(i);
			if (isspace(comando[i])) {
				comandoEsp++;
			}
		}

		if (comandoEsp == 0) {
		  system("cls");
			iss >> str;
			if (str.compare("tempo") == 0) {
				int i = 1;
				mundo->iteracao(i);
				cout << "\n> Passou uma iteracao" << endl;
			}
			else {
				if (str.compare("listamundo") == 0) {
					cout << mundo->getAsString(&x, &y);
				}
				else {
					if (str.compare("sair") == 0) {
						exit(0);
					}
				}
			}
		}
		else {
			if (comandoEsp == 1) {
			  system("cls");
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
				  system("cls");
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
						else if(str.compare("listaposicao") == 0 && num < mundo->getDim() && num2 < mundo ->getDim()) {
							cout << mundo->listaPos(num, num2);
						
						}
					}
				}
				else {
					if (comandoEsp == 3) {
					  system("cls");
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
