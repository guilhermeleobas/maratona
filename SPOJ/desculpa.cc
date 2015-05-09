/*
Problema - Pedido de desculpa
http://br.spoj.com/problems/DESCULPA
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

int main (){
	
	int c, f, peso, custo, test;
	vector<pair<int, int> > mochila;
	int vetor[55][1010];

	test = 0;

	while (true){

		cin >> c >> f;
		if (c == 0 && f == 0) break;

		mochila.clear();
		mochila.push_back (make_pair(0, 0));

		for (int cont=0; cont<f; cont++){
			cin >> peso >> custo;
			mochila.push_back (make_pair(peso, custo));
		}

		for (int i=0; i<f; i++){
			vetor[i][0] = 0;
		}

		for (int j=0; j<c; j++){
			vetor[0][j] = 0;
		}

		for (int i=1; i<mochila.size(); i++){
			for (int j=0; j<=c; j++){

				peso = mochila[i].first;
				custo = mochila[i].second;

				if (peso > j){
					vetor[i][j] = vetor[i-1][j];
				}
				else {
					if ((vetor[i-1][j-peso]+custo) > vetor[i-1][j]){
						vetor[i][j] = vetor[i-1][j-peso] + custo;
					}
					else {
						vetor[i][j] = vetor[i-1][j];
					}
				}
			}
		}

		cout << "Teste " << ++test << endl;
		cout << vetor[f][c] << endl;
		cout << endl;
		/*for (int i=0; i<mochila.size(); i++){
			for (int j=0; j<=c; j++){
				cout << vetor[i][j] << ' ';
			}
			cout << endl;
		}*/
		

	}	

	

	return 0;
}