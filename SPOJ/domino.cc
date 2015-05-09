/*
Problema - Domino
http://br.spoj.com/problems/DOMINO/
Guilherme Leobas
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;

#define for_i(start, end) for (int i=start; i<end; i++)
#define for_j(start, end) for (int j=start; j<end; j++)

// Globais;
int livre[7][7]; // Indica as peças que estão livres [1/0];
int posicao[8][9]; // Indica as posicoes que estão livres [1/0];

int valores[7][8]; // Disposição das peças;

int soma;

ofstream f ("a.txt");

bool got_it (){

	for (int i=0; i<7; i++){
		for (int j=0; j<7; j++){
			if (livre[i][j] == 0) return false;
		}
	}

	return true;

}

bool mark (int i, int j){

	if (posicao[i][j] == 0){
		return true;
	}

	return false;
}

int converte (int p1, int p2){

	int cont = 1;

	int swap;
	if (p1 > p2){
		swap = p1;
		p1 = p2;
		p2 = swap;
	}

	for (int i = 0; i < 7; ++i){
		for (int j=i; j<7; j++){
			if (p1 == i && p2 == j){
				return cont;
			}
			cont++;
		}
	}

	return cont;

}

void imprime (){

	int aux;

	for (int i=0; i<7; i++){
		for (int j=0; j<7; j++){
			f << livre[i][j] << ' ';
		}
		f << "  ";

		for (int j=0; j<8; j++){
			f << valores[i][j] << ' ';
		}

		f << "  ";

		
		for (int j=0; j<8; j++){
			f << posicao[i][j] << ' ';
		}
		f << endl;
	}
	f << endl;
}


void solve (int i, int j){

	int aux;
	int p1, p2;


	if (j > 7){
		solve (i+1, 0);
		return;
	}

	if (i == 6 && j == 7){
		if (got_it()){
			soma++;
		}
		return;
	}

	if (posicao[i][j] == 1){
		solve (i, j+1);
		return;
	}

	// imprime ();

	p1 = valores[i][j];
	p2 = valores[i][j+1];

	if ( posicao[i][j+1] == 0 && livre[p1][p2] == 0){

		// aux = converte (p1, p2);

		// Check
		posicao[i][j] = 1;
		posicao[i][j+1] = 1;
		livre[p1][p2] = 1;
		livre[p2][p1] = 1;

		// Solve;
		solve (i, j+1);

		// Uncheck;
		posicao[i][j] = 0;
		posicao[i][j+1] = 0;
		livre[p1][p2] = 0;
		livre[p2][p1] = 0;
	}

	p1 = valores[i][j];
	p2 = valores[i+1][j];


	if ( posicao[i+1][j] == 0 && livre[p1][p2] == 0){

		// aux = converte (p1, p2);

		// Check;
		livre[p1][p2] = 1;
		livre[p2][p1] = 1;
		posicao[i][j] = 1;
		posicao[i+1][j] = 1;

		// Solve;
		solve (i, j+1);

		// Uncheck;
		livre[p1][p2] = 0;
		livre[p2][p1] = 0;
		posicao[i][j] = 0;
		posicao[i+1][j] = 0;

	}
	
}



int main (){
	
	int t, test, aux;

	test = 0;

	cin >> t;

	while (t-- > 0){

		soma = 0;


		for (int i=0; i<7; i++){
			for (int j=0; j<7; j++){
				livre[i][j] = 0;
			}
		}

		for (int i=0; i<7; i++){
			for (int j=0; j<8; j++){
				cin >> aux;
				valores[i][j] = aux;
				posicao[i][j] = 0;
			}
		}

		for (int i=0; i<8; i++){
			posicao[i][8] = 1;
		}

		for (int i=0; i<9; i++){
			posicao[7][i] = 1;
		}

		solve (0, 0);

		cout << "Teste " << ++test << endl;
		cout << soma << endl;
		cout << endl;

	}
	

	return 0;
}