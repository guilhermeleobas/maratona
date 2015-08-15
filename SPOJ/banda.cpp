/*
Problema - Banda09
http://br.spoj.com/problems/BANDA09/
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
#include <climits>

using namespace std;

void imprime (int *vetor[110]){

	for (int cont=0; cont<110; cont++){
		for (int i=0; i<110; i++){
			cout << vetor[cont][i] << ' ';
		}
		cout << endl;
	}
}

int main (){

	int n, m, x, y, qt, maior;
	int a, b, c;
	vector<vector<int> > v;

	cin >> n >> m;

	v.resize (n);

	for (int cont=0; cont<n; cont++){
		v[cont].resize (n, 0);
	}

	for (int cont=0; cont<m; cont++){
		cin >> x >> y >> qt;

		v[x-1][y-1] = v[y-1][x-1] = qt;
	}

	maior = INT_MIN;

	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++){
			for (int k=j+1; k<n; k++){
				if ((v[i][j] + v[i][k] + v[j][k]) > maior){
					maior = v[i][j] + v[i][k] + v[j][k];
					a = i+1;
					b = j+1;
					c = k+1;
				}
			}
		}
	}

	
	
	cout << a << ' ' << b << ' ' << c << endl;


	


	return 0;
}