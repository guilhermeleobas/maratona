/*
Problema - BracelMG
http://br.spoj.com/problems/BRACELMG/
Guilherme Leobas
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int verifica_direto (string colar, char palavra[102]){

	int valida = 0;

	for (int cont=0; cont<colar.size(); cont++){
		if (palavra[0] == colar[cont]){
			int aux = 1;
			valida = 1;
			while (aux < strlen(palavra) && valida == 1){
				if (palavra[aux] != colar[cont+aux]){
					valida = 0;
				}
				aux++;
			}
			if (valida == 1){
				return valida;
			}
		}
	}

	return valida;
}

int verifica_inverso (string colar, char palavra[102]){

	int valida = 0;

	for (int cont=0; cont<colar.size(); cont++){
		if (palavra[0] == colar[cont]){
			int aux = 1;
			valida = 1;
			while (aux < strlen(palavra) && valida == 1){
				if (palavra[aux] != colar[cont-aux]){
					valida = 0;
				}
				aux++;
			}
			if (valida == 1){
				return valida;
			}
		}
	}

	return valida;
}

int main (){

	//string;
	string colar;
	
	//char;
	char palavra[102];

	//Int;
	int t;
	int tamanho;

	cin >> t;

	while (t-- > 0){

		cin >> palavra;
		cin >> colar;

		colar += colar;

		tamanho = strlen(palavra);

		if (verifica_direto (colar, palavra) || verifica_inverso (colar, palavra)){
			cout << "S\n";
		}
		else {
			cout << "N\n";
		}

		//cout << palavra << " " << colar << endl;


	}


	return 0;
}