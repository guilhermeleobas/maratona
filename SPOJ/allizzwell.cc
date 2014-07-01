/*
Problema - ALLIZZWELL
http://www.spoj.com/problems/ALLIZWEL/
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

int r, c; // r = row (linha), c = coluns (colunas)
char vetor[105][105];
int visited[105][105];
string s = "ALLIZZWELL";
int got_it = 0;

bool mark (int i, int j, int indice){

	if (i >= 0 && i <= r){
		if (j >= 0 && j <= c){
			if (visited[i][j] == 0 && vetor[i][j] == s[indice]){
				return true;
			}
		}
	}

	return false;
}

void imprime_vetor (){
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

void solve (int i, int j, int indice){

	if (indice == s.size()){
		got_it = 1;
		return;
	}

	// imprime_vetor ();

	if (mark (i, j, indice)){
		visited[i][j] = 1;
		for (int linha = -1; linha < 2; linha++){
			for (int coluna = -1; coluna < 2; coluna++){
				solve (i+linha, j+coluna, indice+1);
			}
		}
		visited[i][j] = 0;
	}


}


int main (){
	
	int t;	
	char aux;

	cin >> t;

	while (t-- > 0){

		cin >> r >> c;

		got_it = 0;

		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				cin >> aux;
				vetor[i][j] = aux;
				visited[i][j] = 0;
			}
		}

		for (int i=0; i<r; i++){
			vetor[i][c] = '.';
		}

		for (int j=0; j<c; j++){
			vetor[r][j] = '.';
		}

		vetor[r][c] = '.';

		/*for (int i=0; i<=r; i++){
			for (int j=0; j<=c; j++){
				cout << vetor[i][j] << ' ';
			}
			cout << endl;
		}*/

		int x = 0;
		int y = 0;

		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				solve (i, j, 0);
				if (got_it) break;
			}
			if (got_it) break;
		}

		// solve (0, 0, 0);

		if (got_it == 1){
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}	

	return 0;
}
