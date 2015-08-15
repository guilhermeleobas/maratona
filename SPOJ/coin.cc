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

#define max 100000

int main (){
	
	int vetor[50009];
	vector<int> moedas;
	int n, m, aux;

	while (true){
		scanf ("%d", &m);
		if (m == 0) break;
		scanf ("%d", &n);


		moedas.clear();

		for (int cont=0; cont<=m; cont++){
			vetor[cont] = max;
		}

		for (int cont=0; cont<n; cont++){
			scanf ("%d", &aux);
			moedas.push_back (aux);
		}

		vetor[0] = 0;

		// Vj = moedas disponiveis;
		// Vi = valor a ser pago;
		for (int j=0; j<n; j++){
			for (int i=0; i<=m; i++){
				if (moedas[j] <= i){
					if ( (vetor[i-moedas[j]] + 1) < vetor[i]){
						vetor[i] = vetor[i-moedas[j]]+1;
					}
				}
			}
		}

		if (vetor[m] == max){
			printf ("Impossivel\n");
		}
		else {
			printf ("%d\n", vetor[m]);
		}


	}
	

	return 0;
}