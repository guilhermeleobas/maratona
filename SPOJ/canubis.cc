/*
Problema - Canhão de anubis
http://br.spoj.com/problems/CANUBIS/
Guilherme Leobas
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;

int P[5];
int Q[5];
int S[5];
int normal[5][4];
int vetor[55][4];

int determinante (){

	int p1, p2;

	p1 = normal[0][0]*normal[1][1]*normal[2][2] + normal[1][0]*normal[2][1]*normal[0][2] + normal[2][0]*normal[0][1]*normal[1][2];

	p2 = normal[2][0]*normal[1][1]*normal[0][2] + normal[1][0]*normal[0][1]*normal[2][2] + normal[0][0]*normal[2][1]*normal[1][2];

	return p1-p2;
}

bool equals (int a, int b){
	for (int i=0; i<3; i++){
		if (vetor[a][i] != vetor[b][i]) return false;
	}

	return true;
}

bool diff (int a, int b){
	int dv[3];

	if (normal[a][0]*normal[b][1] == normal[a][1]*normal[b][0] && normal[a][1]*normal[b][2] == normal[a][2]*normal[b][1] && normal[a][0]*normal[b][2] == normal[a][2]*normal[b][0]) return false;

	return true;
}

int get_points (int a, int b, int c, int n){

	int x, y;
	int dv[3];
	int contador = 0;

	if (equals (a, b)){
		x = a; y = b;
	}
	else if (equals (a, c)){
		x = a; y = b;
	}
	else if (equals (b, c)){
		x = b; y = c;
	}
	else {
		x = -1; y = -1;
	}

	if (x != -1 && y != -1){
		for (int aux = 0; aux<n; aux++){
			if (aux == a || aux == b || aux == c) continue;

			if (equals (aux, x)) contador++;
		}

		return contador+2;
	}
	else {
		for (int i=0; i<3; i++){
			normal[1][i] = vetor[c][i] - vetor[b][i];
			normal[2][i] = vetor[a][i] - vetor[b][i];
		}

		if (diff (1, 2) == true){
			for (int aux = 0; aux < n; aux++){
				if (aux == a || aux == b || aux == c) continue;

				for (int i=0; i<3; i++){
					normal[0][i] = vetor[aux][i] - vetor[b][i];
				}

				if (determinante () == 0) contador++;
			}

			return contador + 3;
		}
		else {
			for (int aux=0;aux<n; aux++){
				if (aux == a || aux == b || aux == c) continue;

				for (int i=0; i<3; i++){
					normal[0][i] = vetor[aux][i] - vetor[b][i];
				}

				if (diff (0, 1) == false) contador++;
			}

			return contador+3;
		}
	}

}

int main (){

	// Disable sync with stdio;
	ios::sync_with_stdio (false);

	int t, n, maximo;
	vector<vector<int> > v;

	cin >> t;

	while (t-- > 0){
		cin >> n;

		maximo = 0;

		for (int i=0; i<n; i++){
			for (int j=0; j<3; j++){
				cin >> vetor[i][j];
			}
		}

		for (int i=0; i<n-2; i++){
			for (int j=i+1; j<n-1; j++){
				for (int k=j+1; k<n; k++){
					maximo = max (maximo, get_points (i, j, k, n));
				}
			}
		}

		if (n <= 3) cout << n << endl;
		else cout << maximo << endl;
	
	}



	return 0;
}

