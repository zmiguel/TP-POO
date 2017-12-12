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
					cout << "INICIO FALHADO! ESTAO CONFIGS EM FALTA!!!\n";
				}
			}
			else if (str.compare("file") == 0) {
			  cout << "Intruduza o nome do ficheiro: ";
			  string fileName;
			  string data;
			  getline(cin, fileName);
			  ifstream confFile (fileName);
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
				  cout << "% de posi��es com formigas set " << vall << endl;
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
			  cout << "erro!";
			}
			else if (str.compare("defmundo") == 0 && val >= 10) {
			  cout << "Dimensao do Mundo: " << val << "x" << val << endl;
			  defmundo = val;
			  flag1 = true;
			}
			else if (str.compare("defen") == 0 && val > 0) {
			  cout << "Energia inicial dos ninhos: " << val << endl;
			  defen = val;
			  flag2 = true;
			}
			else if (str.compare("defpc") == 0 && val > 0) {
			  cout << "Valor(em percentagem) da energia inicial a partir do qual o ninho faz uma formiga: " << val << endl;
			  defpc = val;
			  flag3 = true;
			}
			else if (str.compare("defvt") == 0) {
			  cout << "N�mero de unidades de energia transferidas entre ninho e formiga por itera��o: " << val << endl;
			  defvt = val;
			  flag4 = true;
			}
			else if (str.compare("defmi") == 0 && val > 0 && val < 100) {
			  cout << "Percentagem inicial de posicoes com migalhas: " << val << endl;
			  defmi = val;
			  flag5 = true;
			}
			else if (str.compare("defme") == 0 && val > 0) {
			  cout << "Energia inicial de novas migalhas: " << val << endl;
			  defme = val;
			  flag6 = true;
			}
			else if (str.compare("defnm") == 0 && val > 0) {
			  cout << "Numero de migalhas a serem sorteadas a cada instante: " << val << endl;
			  defnm = val;
			  flag7 = true;
			}
			else {
			  flag0 = false;
			  cout << "Sintaxe invalida" << endl;
			}
		  }
		}
		iss.str("");
	}
}