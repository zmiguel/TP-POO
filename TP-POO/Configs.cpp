#include "Configs.h"

void Configs::config(int valor) {

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

	Consola::clrscr();
	cin.clear();
	cin.ignore(100, '\n');

	if (valor == 1) {

		cout << "Configuracao do novo jogo:\n" << "Comandos:\n"
			<< "defmundo - Define o tamanho do mundo\n"
			<< "defen - Define energia inicial dos ninhos\n"
			<< "defpc - Define % de energia necesaria a mais para o ninho criar uma nova formiga\n"
			<< "defvt - Define a energia transferida entre as formigas e o ninho por itera��o\n"
			<< "defme - Define a energia inicial das novas formigas\n"
			<< "defmi - Define a % inicial de casas com migalhas\n"
			<< "defnm - Define o numero maximo de migalhas adicionada a casa itera��o\n\n";

		while (flag0 == true) {

			comandoEsp = 0;

			cout << "> ";
			getline(cin, comando);
			istringstream iss(comando);

			for (int i = 0; i < int(comando.length()); i++) {
				if (isspace(comando[i])) {
					comandoEsp++;
				}
			}

			if (comandoEsp == 0) {
				string str;
				iss >> str;
				if (str.compare("inicio") == 0) {
					if (flag1 == true && flag2 == true && flag3 == true && flag4 == true && flag5 == true && flag6 == true && flag7 == true) {
						Consola::clrscr();
						Consola::setScreenSize(8 + defmundo, 100 + defmundo * 2);
						Mundo *mundo = new Mundo(defmundo, defen, defpc, defvt, defmi, defme, defnm);
						Interface inter(mundo);
						inter.corre();
					}
					else {
						cout << "INICIO FALHADO! ESTAO CONFIGS EM FALTA!!!";
					}
				}
				else {
					cout << "Erro de sintaxe" << endl;
				}
			}
			else {
				if (comandoEsp == 1) {
					string str;
					int val;
					iss >> str;
					iss >> val;

					if (str.compare("defmundo") == 0 && val >= 10) {
						cout << "Dimensao do Mundo: " << val << "x" << val << endl;
						defmundo = val;
						flag1 = true;
					}
					else {
						if (str.compare("defen") == 0 && val > 0) {
							cout << "Energia inicial dos ninhos: " << val << endl;
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
									cout << "N�mero de unidades de energia transferidas entre ninho e formiga por itera��o: " << val << endl;
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
				else {
					flag0 = false;
					cout << "Sintaxe invalida" << endl;
				}
			}
			iss.str("");
		}
	}

	if (valor == 2) {

		cout << "Comando: executa <nome do fichero> - Abrir um ficheiro com configura��o pr�-definida\n\n";

		while (flag0 == true) {
			
			comandoEsp = 0;
			cout << "> ";
			getline(cin, comando);
			istringstream iss(comando);

			for (int i = 0; i < int(comando.length()); i++) {
				if (isspace(comando[i])) {
					comandoEsp++;
				}
			}

			string str;
			string str2;
			int val;
			iss >> str;
			iss >> str2;

			stringstream numb(str2);
			numb >> val;

			if (comandoEsp == 1 && str.compare("executa") == 0) {

				string data;
				ifstream confFile(str2);
				while (confFile.eof() == false) {
					getline(confFile, data);
					istringstream confLine(data);
					string comd;
					int vall;
					confLine >> comd;
					confLine >> vall;
					if (comd.compare("mundo") == 0 && vall >= 10) {
						cout << "Mundo set " << vall << endl;
						defmundo = vall;
						flag1 = true;
					}
					else if (comd.compare("en") == 0 && vall > 0) {
						cout << "Energia Ninhos set " << vall << endl;
						defen = vall;
						flag2 = true;
					}
					else if (comd.compare("pc") == 0 && vall > 0) {
						cout << "% da energia do ninho para criar formigas novas set " << vall << endl;
						defpc = vall;
						flag3 = true;
					}
					else if (comd.compare("vt") == 0 && vall > 0) {
						cout << "Evergia tranferia por itera��o entre a formiga e o ninho set " << vall << endl;
						defvt = vall;
						flag4 = true;
					}
					else if (comd.compare("mi") == 0 && vall > 0 && vall < 100) {
						cout << "% de positions com migalhas set " << vall << endl;
						defmi = vall;
						flag5 = true;
					}
					else if (comd.compare("me") == 0 && vall > 0) {
						cout << "Energia inicial das novas formigas set " << vall << endl;
						defme = vall;
						flag6 = true;
					}
					else if (comd.compare("nm") == 0 && vall > 0) {
						cout << "numero de migalhas adicionadas a cada instante set " << vall << endl;
						defnm = vall;
						flag7 = true;
					}
				}
				confFile.close();
				cout << "Ficheiro lido!!\n";
				if (flag1 == true && flag2 == true && flag3 == true && flag4 == true && flag5 == true && flag6 == true && flag7 == true) {
					Consola::clrscr();
					Consola::setScreenSize(8 + defmundo, 100 + defmundo * 2);
					Mundo *mundo = new Mundo(defmundo, defen, defpc, defvt, defmi, defme, defnm);
					Interface inter(mundo);
					inter.corre();
				}
				else {
					cout << "INICIO FALHADO! ESTAO CONFIGS NO FICHEIRO EM FALTA!!!\n";
				}
			}
		}
	}
}