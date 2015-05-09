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

int vetor[10000000];


int min (int j, int start){
	
	int sum = 0;
	
	sum = vetor[start];
	
	for (int cont=start+1; cont<j+start; cont++){
		if (sum > vetor[cont]){
			sum = vetor[cont];
		}
	}

	return sum;
}

int max_min (int j, int start){

	int m, n;

	m = vetor[start];
	n = vetor[start];
	
	for (int cont=start+1; cont<j+start; cont++){
		if (n > vetor[cont]){
			n = vetor[cont];
		}
		if (m < vetor[cont]){
			m = vetor[cont];
		}
	}

	return m+n;
}

int max (int j, int start){

	int sum = 0;

	sum = vetor[start];

	for (int cont=start+1; cont<j+start; cont++){
		if (sum < vetor[cont]){
			sum = vetor[cont];
		}
	}

	return sum;
}


int main (){

	// Ints;
	int t, e, p, j, aux, cnt, contagem, k;

	// String;
	string nome;
	string resp;

	// cin >> t;
	scanf ("%d", &t);

	while (t-- > 0){
		// cin >> e >> p >> j;
		scanf ("%d%d%d", &e, &p, &j);

		k = 0;
		resp = "ZZZalsjfalkjfd";

		for (int i=0; i<e; i++){
			cin >> nome;
			for (int cnt=0; cnt<p; cnt++){
				// cin >> vetor[cnt];
				scanf ("%d", &vetor[cnt]);
			}
			
			aux = 0;
			contagem = 0;

			while (aux+j-1 < p){
				contagem += max_min (j, aux);
				aux++;
			}

			if (contagem > k){
				resp = nome;
				k = contagem;
			}
			else if (contagem == k){
				if (resp > nome){
					resp = nome;
				}
			}
		}

		cout << resp << ' ' << k << endl;

	}
	

	return 0;
}