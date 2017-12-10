#include "Configs.h"

void Configs::config() {

	string comando;
	int comandoEsp;
	bool flag0 = true;
	bool flag1 = false;
	int defmundo;
	bool flag2 = false;
	int defen;
	bool flag3 = false;
	int defpc;
	bool flag4 = false;
	int defvt;
	bool flag5 = false;
	int defme;
	bool flag6 = false;
	int defmi;
	bool flag7 = false;
	int defnm;
	char nextChar;

	Consola::clrscr();
	cin.clear();
	cin.ignore(100, '\n');

	while (flag0 == true) {

		comandoEsp = 0;

		cout << "> ";
		getline(cin, comando);
		istringstream iss(comando);

		for (int i = 0; i < int(comando.length()); i++) {
			nextChar = comando.at(i);
			if (isspace(comando[i])) {
				comandoEsp++;
			}
		}

		if (comandoEsp == 0) {
			string str;
			iss >> str;
			if (str.compare("inicio") == 0) {
				if (flag1 == true && flag2 == true && flag3 == true && flag4 == true && flag5 == true && flag6 == true && flag7 == true) {
					system("cls");
					Mundo *mundo = new Mundo(defmundo, defen, defpc, defvt, defme, defmi, defnm);
					Interface inter(mundo);
					inter.corre();
				} else {
					cout << "INICIO FALHADO! ESTAO CONFIGS EM FALTA!!!";
				}
			}
			else {
				cout << "Erro de sintaxe"<< endl;
			}
		}
		else {
			if (comandoEsp == 1) {
				string str;
				int val;
				iss >> str;
				iss >> val;

				if (iss.fail()) {
					cout << "Ficheiro aqui";
				}
				else {
					if (str.compare("defmundo") == 0 && val >= 10) {
						cout << "Dimensao do Mundo: " << val << "x" << val << endl;
						defmundo = val;
						flag1 = true;
					}
					else {
						if (str.compare("defen") == 0 && val > 0) {
							cout << "Numero de ninhos: " << val << endl;
							defen = val;
							flag2 = true;
						}
						else {
							if (str.compare("defpc") == 0 && val > 0) {
								cout << "Valor(em percentagem) da energia inicial a partir do qual o ninho faz uma formiga: " << val << endl;
								defpc = val;
								flag3 = true;
							}
							else {
								if (str.compare("defvt") == 0) {
									cout << "Número de unidades de energia transferidas entre ninho e formiga por iteração: " << val << endl;
									defvt = val;
									flag4 = true;
								}
								else {
									if (str.compare("defmi") == 0 && val > 0 && val < 100) {
										cout << "Percentagem inicial de posicoes com migalhas: " << val << endl;
										defmi = val;
										flag5 = true;
									}
									else {
										if (str.compare("defme") == 0 && val > 0) {
											cout << "Energia inicial de novas migalhas: " << val << endl;
											defme = val;
											flag6 = true;
										}
										else {
											if (str.compare("defnm") == 0 && val > 0) {
												cout << "Numero de migalhas a serem sorteadas a cada instante: " << val << endl;
												defnm = val;
												flag7 = true;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				flag0 = false;
				cout << "Sintaxe invalida" << endl;
			}
		}
		iss.str("");
	}
}