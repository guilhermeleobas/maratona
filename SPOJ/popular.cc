/*
Problema - Popularidade
http://br.spoj.com/problems/POPULAR/
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
	
	int n, aux, maior;
	int vetor[105];

	while (true){
		cin >> n;
		if (n == 0) break;

		for (int cont=0; cont<n; cont++){
			vetor[cont] = 0;
		}

		for (int i=0; i<n; i++){
			for (int cont=0; cont<n; cont++){
				cin >> aux;
				vetor[cont] += aux;
			}
		}
		
		maior = vetor[0];
		for (int cont=1; cont<n; cont++){
			if (maior < vetor[cont]){
				maior = vetor[cont];
			}
		}

		cout << maior << endl;
	}

	return 0;
}