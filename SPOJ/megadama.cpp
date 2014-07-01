/*
Problema - MegaDama
http://br.spoj.com/problems/MEGADAMA/
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

int num;
int n, m;

void imprime (int (*vetor)[21], int n, int m){

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cout << vetor[i][j] << ' ';
		}
		cout << endl;
	}
}

bool canI (int i, int j, int ic, int jc, int (*vetor)[21]){

	if (ic < n && jc < m && ic >= 0 && jc >= 0){
		if (vetor[i][j] == 2 && vetor[ic][jc] == 0){
			return true;
		}
	}

	return false;
}

void backtracking (int (*vetor)[21], int x, int y, int contagem){

	int a, b;

	/*for (int i=-1; i<2; i=i+2){
		for (int j=-1; j<2; j=j+2){
			// cout << "i: " << i << " j: " << j << endl;
			
			i < 0 ? a = -1 : a = 1;
			j < 0 ? b = -1 : b = 1;

			if ((x+a+i>=0 && x+a+i <n) && (y+b+j >= 0 && y+b+j<m) && vetor[x+i][y+j] == 2 && vetor[x+i+a][y+j+b] == 0){
				vetor[x][y] = 0;
				vetor[x+i][y+j] = 0;
				vetor[x+i+a][y+j+b] = 1;

				backtracking (vetor, x+i+a, y+j+b, contagem+1);

				vetor[x][y] = 1;
				vetor[x+i][y+j] = 2;
				vetor[x+i+a][y+j+b] = 0;
			}

		}
	}*/

	if (canI (x-1, y-1, x-2, y-2, vetor)){
		vetor[x][y] = 0;
		vetor[x-1][y-1] = 0;
		vetor[x-2][y-2] = 1;
		backtracking (vetor, x-2, y-2, contagem+1);
		vetor[x][y] = 1;
		vetor[x-1][y-1] = 2;
		vetor[x-2][y-2] = 0;
	}

	if (canI (x-1, y+1, x-2, y+2, vetor)){
		vetor[x][y] = 0;
		vetor[x-1][y+1] = 0;
		vetor[x-2][y+2] = 1;
		backtracking (vetor, x-2, y+2, contagem+1);
		vetor[x][y] = 1;
		vetor[x-1][y+1] = 2;
		vetor[x-2][y+2] = 0;
	}

	if (canI (x+1, y-1, x+2, y-2, vetor)){
		vetor[x][y] = 0;
		vetor[x+1][y-1] = 0;
		vetor[x+2][y-2] = 1;
		backtracking (vetor, x+2, y-2, contagem+1);
		vetor[x][y] = 1;
		vetor[x+1][y-1] = 2;
		vetor[x+2][y-2] = 0;
	}

	if (canI (x+1, y+1, x+2, y+2, vetor)){
		vetor[x][y] = 0;
		vetor[x+1][y+1] = 0;
		vetor[x+2][y+2] = 1;
		backtracking (vetor, x+2, y+2, contagem+1);
		vetor[x][y] = 1;
		vetor[x+1][y+1] = 2;
		vetor[x+2][y+2] = 0;
	}

	


	if (num < contagem){
		num = contagem;
	}
}

int main (){

	int max, peca;
	int vetor[21][21];
	vector<pair<int, int> > v;

	// 0 = Casa vazia
	// 1 = Casa amiga;
	// 2 = Casa inimiga;

	while (true){
		cin >> n >> m;


		if (n == 0 && m == 0) break;

		v.clear();
		num = 0;

		max = (n*m/2);

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if ((i+j)%2 != 0)
					vetor[i][j] = 3;
				else
					vetor[i][j] = 0;
			}
		}

		for (int i=0; i<n; i++){
			for (int j=i%2; j<m; j=j+2){
				cin >> peca;
				vetor[i][j] = peca;
				if (peca == 1)
					v.push_back (make_pair(i, j));
			}
		}


		for (int cont=0; cont<v.size(); cont++){
			backtracking (vetor, v[cont].first, v[cont].second, 0);
		}


		// imprime (vetor, n, m);

		cout << num << endl;

	}


	return 0;
}