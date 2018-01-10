#include "Interface.h"
#include "Mundo.h"

Interface::Interface(Mundo * m){
	mundo = m;
}


void Interface::corre() {

	string comando;
	int comandoEsp = 0;
	string str;
	int num;
	int num2;
	int num3;
	char c;

	int x = 0;
	int y = 2;

	mundo->acrescentaMigalhas();

	while (true) {
		
		imprime();
		Consola::gotoxy(0, 1);
		cout << "                    ";

		comandoEsp = 0;
		Consola::gotoxy(0, 0);
		cout << "para ver todos os comandos escreva [help]\n> ";
		getline(cin, comando);
		istringstream iss(comando);

		for (int i = 0; i < int(comando.length()); i++) {
			if (isspace(comando[i])) {
				comandoEsp++;
			}
		}

		if (comandoEsp == 0) {
			Consola::clrscr();
			Consola::gotoxy(0, 2);
			iss >> str;
			if (str.compare("tempo") == 0) {
				int i = 1;
				mundo->iteracao(i);
				imprime();
			}
			else {
				if (str.compare("listamundo") == 0) {
					cout << mundo->getAsString();
				}
				else {
					if (str.compare("sair") == 0) {
						delete mundo;
						exit(0);
					}
				}
			}
		}
		else {
			if (comandoEsp == 1) {
				Consola::clrscr();
				Consola::gotoxy(0, 2);
				iss >> str;
				iss >> num;
				if (iss.fail()) {
					cout << num; // ver isto
				}
				else {
					if (str.compare("tempo") == 0 && num > 0) {
						mundo->iteracao(num);
					}
					else {
						if (str.compare("listaninho") == 0) {
							cout << mundo->listaNinho(num);
						}
						else {
							if (str.compare("inseticida") == 0 && mundo->confirmaNinho(num) == true) {
								mundo->inseticida(num);
							}
						
						}
					}


				}
			}
			else {
				if (comandoEsp == 2) {
					Consola::clrscr();
					Consola::gotoxy(0, 2);
					iss >> str;
					iss >> num;
					iss >> num2;
					if (iss.fail()) {
					
					}
					else {
						if (str.compare("ninho") == 0 && num < mundo->getDim() && num2 < mundo->getDim()) {
							mundo -> acrescentaNinho(num, num2);
							imprime();
						}
						else if(str.compare("listaposicao") == 0 && num < mundo->getDim() && num2 < mundo ->getDim()) {
							cout << mundo->listaPos(num, num2);
						}
						else if (str.compare("migalha") == 0 && num < mundo->getDim() && num2 < mundo ->getDim()) {
							mundo->acrescentaUmaMigalha(num, num2);
						}
						else if (str.compare("mata") == 0 && num < mundo->getDim() && num2 < mundo->getDim()) {
							mundo->assassinaFormiga(num, num2);
						}
						else if (str.compare("energninho") && num2 > 0) {
							mundo->acrescentaEnergiaNinho(num, num2);
						}
					}
				}
				else {
					if (comandoEsp == 3) {
					  Consola::clrscr();
					  Consola::gotoxy(0, 2);
						iss >> str;

					if (str.compare("energformiga") == 0) {
						iss >> num;
						iss >> num2;
						iss >> num3;
						
						
						mundo->acrescentaEnergiaFormiga(num, num2, num3);
					}


						iss >> num;
						if (!iss.fail()) {
							iss >> c;
							if (!iss.fail()) {
								iss >> num3;
								if (!iss.fail()) {
									if (str.compare("criaf") == 0 && num > 0 && (c == 'E' || c == 'C'  || c=='V' || c == 'A' || c == 'T')) {
										if (mundo->existeNinhoID(num3) == true) {
											mundo->trataFormiga(num, num3, c);
											imprime();
										}
									}
									else {
										printf("Erro de sintaxe");
									}
								
								}
							
							}
						}
					
					}
					else {
						if (comandoEsp == 4) {
							Consola::clrscr();
							Consola::gotoxy(0, 2);
								iss >> str;
								iss >> c;
								if (!iss.fail()) {
									iss >> num;
									if (!iss.fail()) {
										iss >> num2;
										if (!iss.fail()) {
											iss >> num3;
											if (!iss.fail()) {
												if (str.compare("cria1") == 0 && (c == 'E' || c == 'C' || c == 'V' || c == 'A' || c == 'T') && num > 0 && num2 >= 0 && num2 < mundo->getDim() && num3 >= 0 && num3 < mundo->getDim()) { // CONDITIONSSSSS
													if (mundo->existeNinhoID(num)) {
														mundo->acrescentaFormiga(c, num, num2, num3);
														imprime();
													}
												}
											}
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

void Interface::imprime() {

	int flag = 0;
	int x = 65;
	int y = 5;
	int xi = 65;
	int yi = 5;
	int itt = 0;

	vector <Elementos*> aux = mundo->getMundo();

	while (x < mundo->getDim() + xi && y < mundo->getDim() + yi) {
		Consola::setTextColor(Consola::AMARELO);
		//imprime reguas
		if (itt == 0) {
			Consola::gotoxy(x + itt * 2 - 5, y);
			cout << y-yi;
		}
		if (yi - y == 0) {
			Consola::gotoxy(x + itt * 2, y - 2);
			cout << itt;
		}
		//end imprime reguas
		Consola::gotoxy(x + itt * 2, y);
		flag = 0;


		for (Elementos* a : aux) {//ve todos os elementos
			if (a->getPosX() + xi == x && a->getPosY() + yi == y) { // verifica se o elemento está na posição onde o corsor está
				if (mundo->ocupaPos2(a->getPosX(), a->getPosY()) == false) { //verifica se a posição ja está ocupada
					flag = 1;
					Consola::setTextColor(a->getIDCor() + 1);

					if (a->getEnergia() > a->getEnergiaInicial()*.5) {
						cout << a->getDenom();
					}
					else {
						putchar(tolower(a->getDenom()));
					}
				}
			}
		}

		if (flag == 0) {
			cout << "*";
		}
		

		if (x - xi == mundo->getDim() - 1) {
			x = xi - 1;
			itt = -1;
			y++;
		}
		x++;
		itt++;
		Consola::setBackgroundColor(Consola::PRETO);
	}
	Consola::setTextColor(Consola::VERDE);
}


Interface::~Interface(){
}
