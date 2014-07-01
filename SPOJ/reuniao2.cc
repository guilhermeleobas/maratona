/*
Problema - Reunião 2
http://br.spoj.com/problems/REUNIAO2/
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
#include <functional>

using namespace std;

#define inf 90000

typedef vector<vector<int> > graph;


void imprime (graph &g){
	for (int i=0; i<g.size(); i++){
		for (int j=0; j<g.size(); j++){
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
}


void floyd (graph &g){

	for (int k=0; k<g.size(); k++){
		for (int i=0; i<g.size(); i++){
			for (int j=0; j<g.size(); j++){
				if (g[i][k] != inf && g[k][j] != inf){
					g[i][j] = min (g[i][j], (g[i][k] + g[k][j]));
				}
			}
		}
	}
}

int main (){
	
	graph g;
	int n, m, u, v, w;

	cin >> n >> m;

	g.resize (n, vector<int> (n, 900000));

	for (int cont=0; cont<m; cont++){
		cin >> u >> v >> w;
		g[u][v] = min (g[u][v], w);
		g[v][u] = min(g[v][u], w);
		// g[v][u] = w;
	}

	for (int i=0; i<n; i++){
		g[i][i] = 0;
	}

	// imprime (g);

	floyd (g);

	int maximo = 0;
	int minimo = inf;

	for (int i=0; i<g.size(); i++){
		maximo = -1;
		for (int j=0; j<g.size(); j++){
			if (i != j && g[i][j] != inf){
				maximo = max (maximo, g[i][j]);
				// cout << "Maximo: " << maximo << endl;
			}
		}
		if (maximo != -1){
			minimo = min (minimo, maximo);
		}
		// cout << "Minimo: " << minimo << endl << endl;
	}

	cout << minimo << endl;

	// imprime (g);
	

	return 0;
}