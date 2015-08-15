/*
Problema - Tenta
http://br.spoj.com/problems/TENTA/
Guilherme Leobas
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int inserir (vector<int> &cartas, int aux){

	//Iterator;
	vector<int>::iterator it;

	//Valida se o numero já não existe no vector;
	int valida = 1;

	for (int cont=0; cont<cartas.size(); cont++){
		if (cartas[cont] == aux){
			valida = 0;
		}
	}

	//Se não existir, adiciona no vector o aux;
	if (valida == 1){
		cartas.push_back (aux);
	}
}

//Imprime o conteúdo do vector;
void imprime (vector<int> &cartas){
	vector<int>::iterator it;

	for (it=cartas.begin(); it!=cartas.end(); it++){
		printf ("%d ", *it);
	}
}

int main (){

	//Vector;
	vector<int> cartas;

	//Iterator;
	vector<int>::iterator it;

	//Ints;
	int aux;
	int quant;

	while (true){

		//Condição de parada;
		scanf ("%d", &quant);
		if (quant == 0) break;

		//Limpa o vector;
		cartas.clear();

		//Adiciona elementos não repetidos ao vector;
		for (int cont=0; cont<quant; cont++){
			scanf ("%d", &aux);
			inserir (cartas, aux);
		}

		//Ordena o vector;
		sort (cartas.begin(), cartas.end());

		//Imprime as permutações;
		do {
			for (int cont=0; cont<quant; cont++){
				printf ("%d ", cartas[cont]);
			}
			printf ("\n");
		} while (next_permutation (cartas.begin(), cartas.end()));
		printf ("\n");
	}




	return 0;
}