/*
Problema - Festa Junina
http://br.spoj.com/problems/JUNINA/
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

using namespace std;

#define for_i(start, end) for (int i=start; i<end; i++)
#define for_j(start, end) for (int j=start; j<end; j++)
#define fori(start, end) for (int i=start; i<end; i++)

typedef vector<vector<int> > vetor;

int particao[20];
int v[20][20];
int melhor = 0;
int n;

void imprime (){
	for (int cont=0; cont<20; cont++){
		cout << particao[cont]+1 << ' ';
	}
	cout << endl;
}

bool godown (int elemento, int k){

	int aux;

	for (int i = 0; i<k; i++){
		aux = particao[i];
		if (v[aux][elemento] == 1){
			return false;
		}
	}

	return true;

}

void backtracking (int u, int k){

	particao[k++] = u;

	if (k > melhor){
		melhor = k;
	}

	for (int i = u+1; i < n; i++){
		if (godown (i, k)){
			backtracking (i, k);
		}
	}

	// return k;
}


void part (){

	int aux;
	int atual = 0;

	for (int cont=0; cont<n; cont++){
		backtracking (cont, 0);
		if (melhor > atual) atual = melhor;
		if (atual == n) return;
	}

	melhor = atual;
}


int main (){

	int aux, test;
	
	test = 0;
	
	while (true){
		cin >> n;
		if (n == 0) break;

		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				v[i][j] = 0;
			}
		}

		for (int i=0; i<20; i++){
			particao[i] = -1;
		}

		melhor = 0;

		for (int cont=0; cont<n; cont++){
			while (true){
				cin >> aux;
				if (aux == 0) break;

				v[cont][aux-1] = 1;
				v[aux-1][cont] = 1;

			}
		}

		part ();

		aux = 0;

		cout << "Teste " << ++test << endl;
		cout << melhor << endl;

		// imprime (v);
		cout << endl;
	}


	return 0;
}