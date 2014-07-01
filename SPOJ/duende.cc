/*
Problema - Duende
http://br.spoj.com/problems/DUENDE/
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

typedef vector<vector<int> > graph;
typedef pair<int, int> par;

bool go (int x, int y, int n, int m){

	if (x >=0 && x<n && y >= 0 && y < m){
		return true;
	}

	return false;
}

int bfs (int v[15][15], int x, int y, int n, int m){

	queue<par> q;
	int visitados[n+1][m+1];
	int a, b;
	par p;

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			visitados[i][j] = 0;
		}
	}

	visitados[x][y] = 0;
	v[x][y] = 1;

	q.push (make_pair(x, y));

	while (!q.empty()){

		p = q.front();
		q.pop();

		a = p.first;
		b = p.second;

		/*for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				cout << v[i][j] << ' ';
			}

			cout << "\t";
			for (int j=0; j<m; j++){
				cout << visitados[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/

		if (go (a-1, b, n, m)){
			if (v[a-1][b] == 1 && visitados[a-1][b] == 0){
				visitados[a-1][b] = visitados[a][b] + 1;
				q.push (make_pair (a-1, b));
				v[a-1][b] = v[a][b] + 1;
			}
			else if (v[a-1][b] == 0) {
				// cout << a-1 << ' ' << b << endl;
				return visitados[a][b] + 1;

			}
		}

		
		if (go(a+1, b, n, m)){
			if (v[a+1][b] == 1 && visitados[a+1][b] == 0){
				visitados[a+1][b] = visitados[a][b] + 1;
				q.push (make_pair(a+1, b));
				v[a+1][b] = v[a][b] + 1;
			}
			else if (v[a+1][b] == 0) {
				// cout << a+1 << ' ' << b << endl;
				return visitados[a][b] + 1;
			}
		}
		
		if (go(a, b-1, n, m)){
			if (v[a][b-1] == 1 && visitados[a][b-1] == 0){
				visitados[a][b-1] = visitados[a][b] + 1;;
				q.push (make_pair (a, b-1));
				v[a][b-1] = v[a][b] + 1;
			}
			else if (v[a][b-1] == 0) {
				// cout << a << ' ' << b-1 << endl;
				return visitados[a][b] + 1;
			}
		}
		
		if (go(a, b+1, n, m)){
			if (v[a][b+1] == 1 && visitados[a][b+1] == 0){
				visitados[a][b+1] = visitados[a][b] + 1;;
				q.push (make_pair(a, b+1));
				v[a][b+1] = v[a][b] + 1;
			}
			else if (v[a][b+1] == 0) {
				// cout << a << ' ' << b+1 << endl;
				return visitados[a][b] + 1;
			}
		}
	
	}

}

int main (){
	
	int v[15][15];
	int n, m, aux, x, y;

	cin >> n >> m;

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			cin >> aux;
			if (aux == 3){
				x = i;
				y = j;
			}
			v[i][j] = aux;
		}
	}

	cout << bfs (v, x, y, n, m) << endl;
	

	return 0;
}